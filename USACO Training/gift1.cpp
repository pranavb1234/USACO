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

int getD(int Y, int M){
    if (M==1 || M==3 || M==5 || M==7 || M==8 || M==10 || M==12)
        {
            return 31;
        }
        else if (M==4 || M==6 || M==9 || M==11)
        {
            return 30;
        }
        else
        {
            if ((Y%100==0 && Y%400==0) || (Y%100!=0 && Y%4==0))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
            
    
}

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
