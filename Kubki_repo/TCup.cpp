#include "TCup.h"
#include "show_formatting.h"
using namespace std;

void TCup::add(TSubstance substance, double volume_in_ml){
    int id_in_cup = search_by_name(substance.get_name(), substances, true);
    if (id_in_cup>=0){
        volumes[id_in_cup] += volume_in_ml / 1e6;
    }
    else{
        substances.push_back(substance);
        volumes.push_back(volume_in_ml / 1e6);
    }
}

void TCup::add(std::string name, double volume_in_ml){
    int _id = search_by_name(name, substancje, false); //wartość domyślna
    if (_id >= 0){
        this->add(substancje[_id], volume_in_ml);
    }
}

void TCup::add_to_volume(TSubstance substance, double volume_coe){
    volume_coe = volume_coe * 0.01;
    double total_volume = get_total_volume();
    int _id = search_by_name(substance.get_name(), substances, true);
    double volume_to_add = 0;
    double volume_in_cup = 0;
    if (_id>=0){
        volume_in_cup = volumes[_id];
    }
    else{
        volume_in_cup = 0;
    }
    volume_to_add =  (volume_coe * total_volume - volume_in_cup)/(1 - volume_coe);
    this->add(substance, volume_to_add * 1e6);
}

void TCup::add_to_volume(std::string name, double volume_coe){
    int _id = search_by_name(name, substancje, false);
    if (_id >= 0){
        this->add_to_volume(substancje[_id], volume_coe);
    }
}

void TCup::add_to_mass(TSubstance substance, double mass_coe){
    mass_coe = mass_coe * 0.01;
    double total_mass = get_total_mass();
    int _id = search_by_name(substance.get_name(), substances, true);
    double volume_to_add = 0;
    double mass_in_cup = 0;
    if (_id>=0){
        mass_in_cup = get_mass(_id);
    }
    else{
        mass_in_cup = 0;
    }
    volume_to_add =  (mass_coe * total_mass - mass_in_cup) / (1 - mass_coe) / substance.get_ro() * 1000;
    this->add(substance, volume_to_add);
}

void TCup::add_to_mass(std::string name, double mass_coe){
    int _id = search_by_name(name, substancje, false);
    if (_id >= 0){
        this->add_to_mass(substancje[_id], mass_coe);
    }
}

void TCup::pour_to(TCup &cup){
    int count = substances.size();
    for (int i = 0; i<count; i++){
        cup.add(substances[i], volumes[i]);
    }
    substances = {};
    volumes = {};
}

void TCup::show(){
    int count = substances.size();
    vector<vector<string>> lines;
    for (int i = 0; i < count; i++){
        vector<string> line = {"| name: ",
                               substances[i].get_name(),
                               "| volume:",
                               to_string(volumes[i] * 1e6) + " ml",
                               "| mass:",
                               to_string(get_mass(i)) + " g",
                               "| \% of volume:",
                               to_string(get_volume_coe(i)) + " \%",
                               "| \% of mass:",
                               to_string(get_mass_coe(i)) + " \%",
                               "|"};
        lines.push_back(line);
    }
    if (lines.size()>0){
        vector<vector<string>> formatted_lines = format_vector(lines);
        print_formatted(formatted_lines);
    }
    else{
        cout<<"---------"<<endl<<"| pusty |"<<endl<<"---------";
    }

}

int TCup::search_by_name(std::string name, std::vector<TSubstance> substance_list, bool silent){
    int count = substance_list.size(); int _id=-1; bool run = true;
    if (count > 0){
        while (run){
            _id += 1;
            string sub_name = substance_list[_id].get_name();
            if (sub_name == name) run = false;
            if ((_id + 1 == count) and (run == true)){
                if (not silent){
                    cout<< "Nie znaleziono płynu o podanej nazwie: \""<< name << "\"!\n";
                }
                run = false;
                _id = -1;
            }
        }
    }
    return _id;
}

double TCup::get_mass(int substance_index){
    return substances[substance_index].get_ro() * volumes[substance_index] * 1000;
}

double TCup::get_mass_coe(int substance_index){
    return get_mass(substance_index) / get_total_mass() * 100;
}

double TCup::get_volume_coe(int substance_index){
    return volumes[substance_index] / get_total_volume() * 100;
}

double TCup::get_total_mass(){
    double total_mass = 0;
    for (int i = 0; i < substances.size(); i++)
        total_mass += get_mass(i);   
    return total_mass;
}

double TCup::get_total_volume(){
    double total_volume = 0;
    for (int i = 0; i < substances.size(); i++)
        total_volume += volumes[i];
    return total_volume;
}