#pragma once
#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
using namespace std;

#define LOGGER logger::getInstance()

#define MODE_INFO  "INFO"
#define MODE_DEBUG "DEBUG"
#define MODE_WARN  "WARN"
#define MODE_ERROR "ERROR"

class logger {

private:
    /** write file location */
    string dir;
    /** write file pointer */
    ofstream ofs;
    /** format */
    string fmt;

    /** singleton */
    logger();
    logger(const logger&);
    logger(string writeDir_);
    ~logger();
    logger& operator=(const logger&);
public:
    /** singleton */
    static logger& getInstance() {
        static logger log;
        return log;
    }
    string get_dir();
    void open_file();
    void debug(string output);
    void write(string output);
    void write(string output, string level);
    void error(string output);
};
#endif