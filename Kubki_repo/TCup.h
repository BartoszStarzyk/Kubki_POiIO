#pragma once
#include <iostream>
#include <vector>

#include "TSubstance.h"

class TCup{
    std::vector<TSubstance> substances;
    std::vector<double> volumes;
    
    public:
    void add(TSubstance substance, double volume_in_ml);
    void add(std::string name, double volume_in_ml);
    void add_to_mass(TSubstance substance, double mass_coe);
    void add_to_mass(std::string name, double mass_coe);
    void add_to_volume(TSubstance substance, double volume_coe);
    void add_to_volume(std::string name, double volume_coe);
    void pour_to(TCup &cup);
    void show();

    private:
    int search_by_name(std::string name, std::vector<TSubstance> substance_list, bool alert=true);
    double get_mass(int substance_index);
    double get_mass_coe(int substance_index);
    double get_volume_coe(int substance_index);
    double get_total_mass();
    double get_total_volume();
};