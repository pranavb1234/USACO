/*
ID: Pranav Bhatia (pranavt6)
TASK: friday
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
    string input_file = "friday.in";
    string output_file = "friday.out";


  
    ofstream fout(output_file);
    ifstream fin(input_file);

    int n;
    fin >> n;

    vector<int> counts(7, 0);
    int daysPassed = 13;  
    
    for (int Y = 1900; Y < 1900 + n; Y++) {
        for (int M = 1; M <= 12; M++) {
            counts[(daysPassed + 1) % 7]++;
            daysPassed += getD(Y, M);
        }
    }
    
    for (int i = 0; i < 6; i++) {
        fout << counts[i] << " ";
    }
    fout << counts[6] << endl;


    return 0;
}

