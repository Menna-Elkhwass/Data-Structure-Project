void Compress::decode(vector<int> code) {
    string s;
    map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);       
        table[i] = ch;       
    }
    int prev = code[0];
    int next;
    string str = table[prev];
    string current = "";
    current += str[0];
    s += str;
  
    int char_count = 256;                               
    for (int i = 0; i < code.size() - 1; i++) {  
        next = code[i + 1];                      
        if (table.find(next) == table.end()) {          
            str = table[prev];                         
            str = str + current;
        }
        else {
            str = table[next];                      
        }
        s += str;
        current = "";
        current += str[0];
        table[char_count] = table[prev] + current;  
        char_count++;
        prev = next;                               
    }
  
}
