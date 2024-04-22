#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;

vector<string> impartire(string str) {
    vector<string> cuvinte;
    string cuv;
    for (char c : str) {
        if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?') {
            if (!cuv.empty()) {
                cuvinte.push_back(cuv);
                cuv.clear();
            }
        }
        else {
            cuv += tolower(c);
        }
    }
    if (!cuv.empty()) {
        cuvinte.push_back(cuv);
    }
    return cuvinte;
}

struct comparare {
    bool operator() (const pair<string, int> a, const pair<string, int> b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        else {
            return a.second < b.second;
        }
    }
};

int main() {
    ifstream file("input.txt");
    string fraza;
    getline(file, fraza);

    vector<string> cuvinte = impartire(fraza);

    map<string, int> nrcuv;
    for (string cuv : cuvinte) {
        ++nrcuv[cuv];
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, comparare> pq;
    for (const auto& intrare : nrcuv) {
        pq.push(intrare);
    }

    while (!pq.empty()) {
        auto intrare = pq.top();
        cout << intrare.first << " => " << intrare.second << endl;
        pq.pop();
    }

    return 0;
}
