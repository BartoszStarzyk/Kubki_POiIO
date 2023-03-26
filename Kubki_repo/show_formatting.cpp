#include <iostream>
#include <vector>
#include "show_formatting.h"

using namespace std;

int max_length(vector <string> args){
    int max = 0;
    for (int i = 0; i < args.size(); i++){
        int len = args[i].length();
        if (len > max){
            max = len;
        }
    }
    return max; 
}

//zakładam, że jest tyle samo słów w każdej linii
vector<int> max_length_column(vector <vector<string>> args){
    vector <int> sizes;
    for (int i = 0; i < args[0].size(); i++){
        vector <string> column;
        for (int j = 0; j < args.size(); j++){
            column.push_back(args[j][i]);
        }
        sizes.push_back(max_length(column));
    }
    return sizes;
}

vector <vector<string>> format_vector(vector <vector<string>> args){
    vector <int> sizes = max_length_column(args);
    vector <vector<string>> results;
    for (int line = 0; line < args.size(); line++){
        vector <string> temp_line;
        for (int word = 0; word < args[line].size();word++){
            temp_line.push_back(args[line][word]);
            string spaces = "";
            for (int space = 0; space < (sizes[word]-args[line][word].length()+1); space++){
                spaces += " ";
            }
            temp_line.push_back(spaces);
        }
        results.push_back(temp_line);
    }
    return results;
}

void print_formatted(vector<vector<string>> formatted_lines){
    string line_separator = "";
    int line_length = 0;
            for (int word = 0; word < formatted_lines[0].size() - 1;word++)
                for (int character = 0; character < formatted_lines[0][word].length(); character++){
                    line_separator += "-";
                }
    cout<<line_separator<<endl;
    for (int line = 0; line < formatted_lines.size(); line++){
            for (int word = 0; word < formatted_lines[line].size();word++){
                cout<<formatted_lines[line][word];
            }
            cout<<endl; cout<<line_separator; cout<<endl;
        }
}

