#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void AnalyzeFile(char user_char);

int main() {
    char user_char;
    cout << "Enter a character to check the beginning of lines: ";
    cin >> user_char;

    AnalyzeFile(user_char);

    return 0;
}

void AnalyzeFile(char user_char) {
    ifstream infile("t.txt");
    ofstream outfile("result.txt");

    if (!infile.is_open()) {
        cout << "Failed to open file for reading!" << endl;
        return;
    }

    if (!outfile.is_open()) {
        cout << "Failed to open file for writing!" << endl;
        return;
    }

    int start_with_user_char = 0;
    int start_end_same = 0;
    int identical_chars = 0;
    int empty_lines = 0;

    string line;
    while (getline(infile, line)) {
        if (line.empty()) {
            empty_lines++;
            continue;
        }

        if (line[0] == user_char) {
            start_with_user_char++;
        }

        if (line.front() == line.back()) {
            start_end_same++;
        }

        bool all_identical = true;
        for (char c : line) {
            if (c != line[0]) {
                all_identical = false;
                break;
            }
        }
        if (all_identical) {
            identical_chars++;
        }
    }

    outfile << "Number of lines starting with character '" << user_char << "': " << start_with_user_char << endl;
    outfile << "Number of lines starting and ending with the same character: " << start_end_same << endl;
    outfile << "Number of lines with identical characters: " << identical_chars << endl;
    outfile << "Number of empty lines: " << empty_lines << endl;

    infile.close();
    outfile.close();
    cout << "Analysis completed. Results saved to result.txt." << endl;
}
