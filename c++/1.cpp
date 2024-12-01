#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> firstColumn;
vector<int> lastColumn;

void readInput() {
    ifstream input{"../../data/1.txt"};

    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        int first, second;
        iss >> first >> second;

        firstColumn.push_back(first);
        lastColumn.push_back(second);
    }
}

int totalDistance() {
    int total = 0;

    for (int i = 0; i < firstColumn.size(); i++) {
        total += abs(lastColumn[i] - firstColumn[i]);
    }

    return total;
}

int similarity() {
    int total = 0;

    for (const int x: firstColumn) {
        total += x * (int) ranges::count(lastColumn, x);
    }

    return total;
}

int main() {
    readInput();
    ranges::sort(firstColumn);
    ranges::sort(lastColumn);

    cout << totalDistance() << endl;
    cout << similarity() << endl;

    return 0;
}
