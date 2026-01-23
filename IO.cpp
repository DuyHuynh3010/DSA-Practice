#include <iostream>
using namespace std;
#include <string>

bool isNumber(const string& s) {
    if (s.empty()) return false;

    bool hasDecimal = false;

    for (char c : s) {
        if (c == '.') {
            if (hasDecimal) return false; 
            hasDecimal = true;
        }
        else if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string sentence;
    cout << "Sentence: ";
    getline(cin, sentence);

    string word = "";

    for (int i = 0; i <= sentence.length(); i++) {
        if (i == sentence.length() || sentence[i] == ' ') {
            if (!word.empty()) {
                if (isNumber(word)) {
                    double num = stod(word);
                    cout << num * 2 << endl;
                } else {
                    cout << word << endl;
                }
                word = "";
            }
        }
        else {
            word += sentence[i];
        }
    }

    return 0;
}