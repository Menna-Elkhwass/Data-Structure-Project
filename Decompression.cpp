void Compress::decode(vector<int> decoded_code) {
    string s;
    map<int, string> decoded_table;
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
