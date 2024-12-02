#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool equal(const vector<int>& reports, const vector<int>& sorted_reports) {
    for (int i = 0; i < reports.size(); i++) {
        if (reports[i] != sorted_reports[i]) return false;
        if (i + 1 == reports.size()) return true;
        if (const int difference = abs(reports[i] - reports[i + 1]); difference > 3 or difference < 1) return false;
    }
    return true;
}

bool safe(const vector<int>& reports) {
    vector<int> sorted_reports = reports;
    ranges::sort(sorted_reports);
    if (equal(reports, sorted_reports)) return true;

    ranges::reverse(sorted_reports);
    return equal(reports, sorted_reports);
}

int main() {
    int part1 = 0;
    int part2 = 0;
    ifstream input{"../../data/2.txt"};

    string line;
    while (getline(input, line)) {
        vector<int> reports;

        istringstream stream(line);
        string word;
        while (stream >> word) {
            reports.push_back(stoi(word));
        }

        if (safe(reports)) {
            part1 += 1;
            part2 += 1;
            continue;
        }

        for (int i = 0; i < reports.size(); i++) {
            vector<int> shorterReports(reports.begin(), reports.begin() + i);
            shorterReports.insert(shorterReports.end(), reports.begin() + i + 1, reports.end());

            if (safe(shorterReports)) {
                part2 += 1;
                break;
            };
        }
    }

    cout << to_string(part1) << endl;
    cout << to_string(part2) << endl;
}
