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
    string str = decoded_table[prev];
    string current = "";
    current += str[0];
    s += str;
  
    int char_count = 256;                               
    for (int i = 0; i < decoded_code.size() - 1; i++) {  
        next = decoded_code[i + 1];                      
        if (decoded_table.find(next) == decoded_table.end()) {          
            str = decoded_table[prev];                         
            str = str + current;
        }
        else {
            str = decoded_table[next];                      
        }
        s += str;
        current = "";
        current += str[0];
        decoded_table[char_count] = decoded_table[prev] + current;  
        char_count++;
        prev = next;                               
    }
  
}
