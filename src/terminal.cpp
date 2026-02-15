#include "unistd.h"
#include "terminal.h"

logger log;

terminal::terminal() {
    log.log("terminal constructor start");

    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    orig_term = term;
    term = setRawFlags(term);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

    log.log("terminal constructor end");
}

terminal::~terminal() {
    log.log("terminal destructor start");
    
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_term);

    log.log("terminal destructor end");
}

termios terminal::setRawFlags(struct termios term) {
    log.log("setRawFlags() start");
    term.c_lflag &= ~(ECHO | ICANON);

    term.c_cc[VSUSP] = _POSIX_VDISABLE;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
    log.log("setRawFlags() end");
    return term;
}