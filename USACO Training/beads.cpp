/*
ID: Pranav Bhatia (pranavt6)
TASK: beads
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int N, leftOver;
vector<string> colors;

int next(int i) {
    return (i + 1) % N;
}

int prev(int i) {
    return (i - 1 + N) % N;
}

int prev(int i, int n) {
    int answer = i;
    for (int c = 0; c < n; c++) {
        answer = prev(answer);
    }
    return answer;
}

int countFwd(int i) {
    string color = "w";
    int count = 0;
    bool first = true;
    for (int c = i; c != i || first; c = next(c)) {
        if (color != "w" && (color == colors[c] || colors[c] == "w")) {
            count++;
        } else if (color == "w") {
            color = colors[c];
            count++;
        } else {
            break;
        }
        first = false;
    }
    leftOver = N - count;
    return count;
}

int countBwd(int i) {
    string color = "w";
    int count = 0;
    if (leftOver == 0) return 0;
    for (int c = i; c != prev(i, leftOver); c = prev(c)) {
        if (color != "w" && (color == colors[c] || colors[c] == "w")) {
            count++;
        } else if (color == "w") {
            color = colors[c];
            count++;
        } else {
            break;
        }
    }
    return count;
}

vector<string> breakToArray(const string& str) {
    vector<string> array(str.length());
    for (int c = 0; c < str.length(); c++) {
        array[c] = str.substr(c, 1);
    }
    return array;
}



int main() {
    string input_file = "beads.in";
    string output_file = "beads.out";


  
    ofstream fout(output_file);
    ifstream fin(input_file);

    fin >> N;
    string beadsString;
    fin >> beadsString;

    int max = 0;
    colors = breakToArray(beadsString);

    for (int i = 0; i < N; i++) {
        int forwardCount = countFwd(i);
        int backwardCount = countBwd(prev(i));
        if (forwardCount + backwardCount > max) {
            max = forwardCount + backwardCount;
        }
    }

    fout << max << endl;

        return 0;
}
