#include <string>
#include <vector>
#include "JSON.h"
#include "util.h"

JSON::JSON(const vector<string> json_str) {
    JSON(json_str ,0, 0);
}

JSON::JSON(const vector<string> json_str, 
    u_int64_t column, u_int64_t row) {
    
    JSON json;
    string buf = "";
    string key;
    /** true while search inside the double-quot(") */
    bool hasQuot;
    /** true while search inside the parenthesis([]) */
    bool isArr;
    /**  */
    int start = -1, end = -1;

    // make json object
    for (int i = column; i < json_str.size(); i++) {
    
        for (int j = i == column ? row : 0 ; j < json_str[i].size(); j++) {
            // search the key
            if (key.empty()) {
                if (start == -1 && json_str[i][j] == '"') {
                    hasQuot = true;
                    start = j+1;
                } else if (hasQuot && json_str[i][j] == '"') {
                    // read inside the quot e.g. "aaa" -> aaa
                    key = json_str[i].substr(start, j);
                    start = -1;
                }
                continue;
            }
            // search value associated with the key that last found
            char c = json_str[i][j];
            switch (c) {
                // recurse to create child JSON node when start of parentheses
                case '{':
                    if (isArr) {
                        
                    }
                    json.child = new JSON(json_str, i, j);
                    break;
                case '[':
                    isArr = true;
                    break;
                case ']':
                    isArr = false;
                    break;
                case '"':
                    if (!hasQuot) {
                        start = j+1;
                        hasQuot = true;
                    } else if (hasQuot && isArr) {
                        json.arr_val.emplace_back(json_str[i].substr(start, j));
                        hasQuot = false;
                    } else if (hasQuot) {
                        json.val = json_str[i].substr(start, j);
                    } 
                    break;

            }
        }
    }
}

JSON JSON::parse(string str) {

}