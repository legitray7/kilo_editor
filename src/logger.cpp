#include <format>
#include <sys/stat.h>

#include "logger.h"
#include "util.h"

using namespace std;
using namespace util;

logger::logger(): dir("log/kilo.log")
{
    open_file();
};

logger::logger(string writeDir_): dir(writeDir_)
{
    open_file();
};

logger::~logger() {
    ofs.close();
}

string logger::getDir() {
    return dir;
}

void logger::open_file() {
    mkdir("./log", 0777);
    ofs.open(dir, std::ios::app);
    if (!ofs.is_open()) {
        perror("cannot open file");
        exit(1);
    }
}

void logger::debug(string output) {
    ofs << format("[{:<5}]{} : {}\n", MODE_DEBUG, get_time(), output);
    ofs.flush();
}

void logger::log(string output) {
    ofs << format("[{:<5}]{} : {}\n", MODE_INFO, get_time(), output);
    ofs.flush();
}

void logger::log(string output, string level) {
    ofs << format("[{:<5}]{} : {}\n", level, get_time(), output);
    ofs.flush();
}

void logger::error(string output) {
    ofs << format("[{:<5}]{} : {}\n", MODE_ERROR, get_time(), output);
    ofs.flush();
}