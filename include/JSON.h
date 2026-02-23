#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

class JSON {

private:
    map<string, void*> key_value;
    JSON* child;
public:
    JSON();
    JSON(const vector<string> json_str);
    JSON(const vector<string> json_str, u_int64_t column , u_int64_t row);
    JSON(const string str);
    ~JSON();

    JSON parse(string str);
    string stringify(JSON json);
};