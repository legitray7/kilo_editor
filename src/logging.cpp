#include <format>
#include <sys/stat.h>

#include "logging.h"
#include "util.h"

using namespace std;
using namespace util;

Logger::Logger(): dir("log/kilo.log")
{
    open_file();
};

Logger::Logger(string writeDir_): dir(writeDir_)
{
    open_file();
};

Logger::~Logger() {
    ofs.close();
}

string Logger::getDir() {
    return dir;
}

void Logger::open_file() {
    mkdir("./log", 0777);
    ofs.open(dir, std::ios::app);
    if (!ofs.is_open()) {
        perror("cannot open file");
        exit(1);
    }
}

void Logger::debug(string output) {
    ofs << format("[{:<5}]{} : {}\n", MODE_DEBUG, get_time(), output);
    ofs.flush();
}

void Logger::log(string output) {
    ofs << format("[{:<5}]{} : {}\n", MODE_INFO, get_time(), output);
    ofs.flush();
}

void Logger::log(string output, string level) {
    ofs << format("[{:<5}]{} : {}\n", level, get_time(), output);
    ofs.flush();
}

void Logger::error(string output) {
    ofs << format("[{:<5}]{} : {}\n", MODE_ERROR, get_time(), output);
    ofs.flush();
}