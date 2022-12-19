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
