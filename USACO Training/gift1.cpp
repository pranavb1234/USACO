/*
ID: Pranav Bhatia (pranavt6)
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;



int main() {
    string input_file = "gift1.in";
    string output_file = "gift1.out";


  
    ofstream fout(output_file);
    ifstream fin(input_file);

    int np;
    fin >> np;
    map<string, int> mp;
    vector<string> names;

    for(int i=0;i<np;i++){
        string temp;
        fin >> temp;
        names.push_back(temp);
        mp[temp] = 0;
    }

    while(np--){
        string giver;
        fin >> giver;
        int amount; 
        int givenThm;
        fin >> amount >> givenThm;
        if(givenThm > 0){
            int gift_per_person = amount / givenThm;  
            int remainder = amount % givenThm;
        while(givenThm--){
            string taker;
            fin >> taker;
            mp[taker] = mp[taker] + gift_per_person;
        }
        mp[giver] = mp[giver] - amount + remainder;
        }
    }

    map<string, int>::iterator it = mp.begin();

    
    for(auto x : names){
        fout << x << " " << mp[x] << '\n';
    }

    return 0;
}
