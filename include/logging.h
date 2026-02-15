#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
using namespace std;

#define MODE_INFO  "INFO"
#define MODE_DEBUG "DEBUG"
#define MODE_WARN  "WARN"
#define MODE_ERROR "ERROR"

class Logger {

    private:
        /** log file location */
        string dir;
        /** log file pointer */
        ofstream ofs;
        /** format */
        string fmt;
    public:
        Logger();
        Logger(string writeDir_);
        ~Logger();
        void open_file();
        string getDir();
        void debug(string output);
        void log(string output);
        void log(string output, string level);
        void error(string output);
};
#endif