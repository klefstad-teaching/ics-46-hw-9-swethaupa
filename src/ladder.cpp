#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout << "Error: " << msg << word1 << ", " << word2 << endl;
}

bool is_adjacent(const string& word1, const string& word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    
    if (abs(len1 - len2) > 1) {
        return false;
    }
    int differences = 0;
    int i = 0;
    int j = 0;
    
    while (i < len1 && j < len2) {
        if (word1[i] != word2[j]) {
            differences++;
            
            if (differences > 1) {
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
    
    return differences == 1;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
   queue<vector<string>> ladder_queue;
   ladder_queue.push({begin_word});
   set<string> visited;
   visited.insert(begin_word);
   
   while (!ladder_queue.empty()) {
       vector<string> ladder = ladder_queue.front();
       ladder_queue.pop();
       string last_word = ladder.back();
       for (const string& word : word_list) {
           if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
               vector<string> new_ladder = ladder;
               new_ladder.push_back(word);
               
               if (word == end_word) {
                   return new_ladder;
               }
               
               ladder_queue.push(new_ladder);
               visited.insert(word);
           }
       }
   }
   
   return {};
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
    
    cout << ladder[0];
    for (size_t i = 1; i < ladder.size(); i++) {
        cout << " → " << ladder[i];
    }
    cout << endl;
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");

    cout << "Testing Word Ladder Function:" << endl;
    
    print_word_ladder(generate_word_ladder("cat", "dog", word_list));
    print_word_ladder(generate_word_ladder("marty", "curls", word_list));
}