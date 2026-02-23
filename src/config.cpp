#include <fstream>
#include <string>

#include "logger.h"
using namespace std;

string read_ini(const string& path, const string& field) {
    ofstream ofs(path);
    if (!ofs) {
        LOGGER.error("ini file not found");
        -1;
    }
    
}