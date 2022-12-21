#include "Map.h"
vector<int> Compress::compress_file(string file_encode) {
    Map<string, int> encoded_table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        encoded_table[ch] = i;
    }
    int char_code = 256;
    string current = "", next = "";
    vector<int> encoded_code;
    current += file_encode[0];
    for (int i = 0; i < file_encode.length(); i++) {
        if (i != file_encode.length() - 1) {           //While the input stream is not ended
            next += file_encode[i + 1];               //Next character = next input character
        }
        if (encoded_table.find(current + next) != encoded_table.end()) {   //If current character + next character is in the string table
            current = current + next;
        }
        else {
            encoded_code.push_back(encoded_table[current]);   //Add the table value of current character into code vector.
            encoded_table[current + next] = char_code;       //Add current character and next character to the table with value of multiple character code.
            char_code++;
            current = next;
        }
        next = "";
    }
    encoded_code.push_back(encoded_table[current]);      //Add the table value of current character into code vector.
    return encoded_code;
}
void Compress::decode(vector<int> decoded_code) {
    string s;
    Map<int, string> decoded_table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);       
        decoded_table[i] = ch;       
    }
    int prev = decoded_code[0];
    int next;
    string str = decoded_table[prev];           //Get the string corresponds to old in the table into str
    string current = "";
    current += str[0];
    s += str;
  
    int char_count = 256;                               
    for (int i = 0; i < decoded_code.size() - 1; i++) {  //While the input stream is not ended
        next = decoded_code[i + 1];                     //New = next input code            
        if (decoded_table.find(next) == decoded_table.end()) {     //If new is not the string table     
            str = decoded_table[prev];            //Str = string corresponds to old in the table                   
            str = str + current;
        }
        else {
            str = decoded_table[next];          //Str = string corresponds to new in the table            
        }
        s += str;
        current = "";
        current += str[0];                                           //current character = first character in str
        decoded_table[char_count] = decoded_table[prev] + current;  //Add the previous and current character in the table.
        char_count++; 
        prev = next;                               
    }
  
}
