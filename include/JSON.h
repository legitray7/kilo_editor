#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

class JSON {

private:
    string key;
    void *value;
public:
    JSON();
    JSON(const vector<string> json_str);
    JSON(const string str);
    ~JSON();

    JSON parse(string str);
    string stringify(JSON json);

    JSON get_object(const vector<string>& json_str, 
        u_int64_t column , u_int64_t row) throw();
};