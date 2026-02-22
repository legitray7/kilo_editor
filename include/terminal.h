#pragma once
#include <termios.h>
#include "logger.h"
using namespace std;

class terminal {
private:
    struct termios orig_tty;
public:
    terminal();
    ~terminal();
    termios setRawFlags(struct termios term);
};