#include <format>
#include <sys/stat.h>

#include "logger.h"
#include "util.h"

using namespace std;

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

string logger::get_dir() {
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
    ofs << format("[{:<5}]{} : {}\n", MODE_DEBUG, util::get_time(), output);
    ofs.flush();
}

void logger::write(string output) {
    ofs << format("[{:<5}]{} : {}\n", MODE_INFO, util::get_time(), output);
    ofs.flush();
}

void logger::write(string output, string level) {
    ofs << format("[{:<5}]{} : {}\n", level, util::get_time(), output);
    ofs.flush();
}

void logger::error(string output) {
    ofs << format("[{:<5}]{} : {}\n", MODE_ERROR, util::get_time(), output);
    ofs.flush();
}