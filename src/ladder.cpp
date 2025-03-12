#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout << "Error: " << msg << word1 << ", " << word2 << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.size();
    int len2 = str2.size();
    if (abs(len1 - len2) > d) {
        return false;
    }
    
    int differences = 0;
    int i = 0;
    int j = 0;
    
    while (i < len1 && j < len2) {
        if (str1[i] != str2[j]) {
            differences++;
            if (differences > d) {
                return false;
            }
            
            if (len1 > len2) {
                i++;
            }
            else if (len1 < len2) {
                j++;
            }
            else {
                i++;
                j++;
            }
        } 
        else {
            i++;
            j++;
        }
    }
    
    differences += (len1 - i) + (len2 - j);
    return differences <= d;
}

void load_words(set<string>& word_list, const string& file_name) {
    ifstream file(file_name);
    if (!file) {
        cout << "Error: Unable to open" << file_name << endl;
        return;
    }
    
    string word;
    while (file >> word) {
        word_list.insert(word);
    }
    
    file.close();
}


void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No ladder found" << endl;
        return;
    }
    for (size_t i = 0; i < ladder.size(); i++) {
        cout << ladder[i] << " ";
    }
    cout << endl;
    cout << "Ladder length: " << ladder.size() << endl;
}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");

    cout << "Testing Word Ladder Function:" << endl;
    
    print_word_ladder(generate_word_ladder("cat", "dog", word_list));
    print_word_ladder(generate_word_ladder("marty", "curls", word_list));
}