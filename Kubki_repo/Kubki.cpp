#include <iostream>
#include <vector>
#include "TSubstance.h"
#include "TCup.h"

using namespace std;

int main(){
    TCup kubek1, kubek2, kubek3, kubek4;
    
    kubek1.add(substancje[0], 100.1);
    kubek1.add("mleko", 102.3);
    kubek1.add("kreww", 52.5);
    kubek1.add_to_volume(substancje[1], 15);
    kubek1.add_to_volume("olia", 15);

    kubek2.add(substancje[2], 360.02);
    kubek2.add_to_mass(substancje[1], 10);
    kubek2.add_to_mass("mlejo", 5);
  
    kubek3.add(substancje[3], 150.34);
    kubek3.add_to_mass("mleko", 50);

    kubek4.add(substancje[3], 20);
    kubek4.add_to_volume("oliwa", 10);


    cout<<endl<<"kubek1:"<<endl;
    kubek1.show();
    cout<<endl<<endl<<"kubek2:"<<endl;
    kubek2.show();
    cout<<endl<<endl<<"kubek3:"<<endl;
    kubek3.show();
    cout<<endl<<endl<<"kubek4:"<<endl;
    kubek4.show();

    kubek1.pour_to(kubek2);

    cout<<endl<<endl<<"kubek1 po przelaniu"<<endl;
    kubek1.show();
    cout<<endl<<endl<<"kubek2 po przelaniu"<<endl;
    kubek2.show();

    return 0;
}

