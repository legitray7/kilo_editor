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
    int init_termios();
    int init_screen();
    int restore_screen();
    termios set_flags(struct termios term);
};