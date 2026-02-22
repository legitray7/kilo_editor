#include <string>
#include <ctime>

#include "util.h"
#include "logger.h"
using namespace std;

string util::get_time() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", now);
    return string(buf);
}