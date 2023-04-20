#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
int main() {
    string words[100];
    std::string sentence;
    std::cout << "Cumlegirlan:";
    std::getline(std::cin, sentence);
    int arraysayi = 0;
    std::stringstream ss(sentence);
    std::string word;
    while (ss >> word) {
        for (int i = 0; i < word.length(); i++) {
            cout << word[i] << " ";
            words[arraysayi] += word[i];
            arraysayi++;
        }
    }
    cout << "\Ascii sayi\n";
    for (int a = 0; a < 100; a++) {
        for (char c : words[a]) {
            int gg = static_cast<int>(c);
            std::cout<< gg << " ";
        }
    }
    cout << endl;
    return 0;
}
