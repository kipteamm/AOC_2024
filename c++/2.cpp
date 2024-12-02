#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool areValid(const vector<int>& reports, const vector<int>& sortedReports) {
    int previous = reports[0];
    for (int i = 1; i < reports.size(); i++) {
        if (reports[i] != sortedReports[i]) return false;
        if (int difference = abs(reports[i] - previous); difference > 3 || difference < 1) return false;
        previous = reports[i];
    }

    return true;
}

int main() {
    int save = 0;
    ifstream input{"../../data/2.txt"};

    string line;
    while (getline(input, line)) {
        vector<int> reports;

        istringstream stream(line);
        string word;
        while (stream >> word) {
            reports.push_back(stoi(word));
        }

        vector<int> sortedReports(reports);
        sort(sortedReports.begin(), sortedReports.end());
        if (areValid(reports, sortedReports)) {
            save += 1;
            continue;
        }

        reverse(sortedReports.begin(), sortedReports.end());
        if (!areValid(reports, sortedReports)) continue;
        save += 1;
    }

    cout << to_string(save) << endl;
}