#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

char convertToLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

int main() {
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    vector<string> uniqueWords;
    vector<int> wordFrequencies;

    string currentWord = "";
    for (char character : paragraph) {
    
        if (isLetter(character)) {
            currentWord += convertToLower(character);
        } else if (!currentWord.empty()) {
           
            bool wordFound = false;
            for (int i = 0; i < uniqueWords.size(); i++) {
                if (uniqueWords[i] == currentWord) {
                    wordFrequencies[i]++;
                    wordFound = true;
                    break;
                }
            }
           
            if (!wordFound) {
                uniqueWords.push_back(currentWord);
                wordFrequencies.push_back(1);
            }
            currentWord = ""; 
        }
    }

   
    if (!currentWord.empty()) {
        bool wordFound = false;
        for (int i = 0; i < uniqueWords.size(); i++) {
            if (uniqueWords[i] == currentWord) {
                wordFrequencies[i]++;
                wordFound = true;
                break;
            }
        }
        if (!wordFound) {
            uniqueWords.push_back(currentWord);
            wordFrequencies.push_back(1);
        }
    }
    cout << "Word frequencies:" << endl;
    for (int i = 0; i < uniqueWords.size(); i++) {
        cout << uniqueWords[i] << ": " << wordFrequencies[i] << endl;
    }

    return 0;
}
