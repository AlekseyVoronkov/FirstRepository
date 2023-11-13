#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {

    ifstream file("text.txt");

    if (!file) {
        cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    map <char, int> letterFrequency;
    map <string, int> combinationFrequency;

    string line;
    
    while (getline (file, line) ) {
        for (size_t i = 0; i < line.length(); ++i) {
            ++letterFrequency[line[i]];
    
            if (i + 1 < line.length()) {
                string combination = line.substr(i, 2);
                ++combinationFrequency[combination];
            }
        }
    }

    cout << "Частота повторения букв:" << endl;
    for (const auto& pair : letterFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Выводим частоту повторения двухбуквенных сочетаний
    cout << "Частота повторения двухбуквенных сочетаний:" << endl;
    for (const auto& pair : combinationFrequency) {
        std::cout << pair.first << ": " << pair.second << endl;
    }

    file.close();

    return 0;
}