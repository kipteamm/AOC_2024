#include <regex>
#include <fstream>
#include <iostream>
using namespace std;


int main() {
    regex multi_match(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");
    ifstream input{"../../data/3.txt"};

    int part1 = 0;
    int part2 = 0;
    bool allowed = true;

    string line;
    while (getline(input, line)) {
        for (std::sregex_iterator it(line.begin(), line.end(), multi_match), end; it != end; ++it) {
            const auto& match = *it;
            const string matchName = match.str();

            if (matchName == "don't()") {
                allowed = false;
                continue;
            }

            if (matchName == "do()") {
                allowed = true;
                continue;
            }

            int a = std::stoi(match[1].str());
            int b = std::stoi(match[2].str());
            int value = a * b;

            part1 += value;
            if (!allowed) continue;
            part2 += value;
        }
    }

    cout << to_string(part1) << endl;
    // >>> 173517243
    cout << to_string(part2) << endl;
    // >>> 100450138
}