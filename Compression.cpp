void Compress::decode(vector<int> output_code) {
    string s;
    map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);        //Current character = first input character
        table[i] = ch;       //Initialize table with single character strings (256 entries)
    }
    int prev = output_code[0];
    int next;
    string str = table[prev];
    string current = "";
    current += str[0];
    s += str;
  
    int char_count = 256;                               //multiple character code = 256
    for (int i = 0; i < output_code.size() - 1; i++) {  //While the input stream is not ended
        next = output_code[i + 1];                      //Next character = next input char
        if (table.find(next) == table.end()) {          //IF current character + next character is in the string table
            str = table[prev];                          //Current character = current character + next character
            str = str + current;
        }
        else {
            str = table[next];                      //Add the table value of current_char into code vector.
        }
        s += str;
        current = "";
        current += str[0];
        table[char_count] = table[prev] + current;   //Add current character and next character to the table with value of multiple character code.
        char_count++;
        prev = next;                                 //take the current one to the next one
    }
  
  return output_code;
}
