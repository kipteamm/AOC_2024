#include <regex>
#include <fstream>
#include <iostream>
using namespace std;


int main() {
    regex mul_match(R"(mul\((\d{1,3}),(\d{1,3})\))");
    ifstream input{"../../data/3.txt"};

    int total = 0;
    string line;
    while (getline(input, line)) {
        for (std::sregex_iterator it(line.begin(), line.end(), mul_match), end; it != end; ++it) {
            int a = std::stoi((*it)[1].str());
            int b = std::stoi((*it)[2].str());

            total += a * b;
        }
    }

    cout << to_string(total) << endl;
    // >>> 173517243
}