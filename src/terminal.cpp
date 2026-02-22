#include "unistd.h"
#include "terminal.h"
#include "util.h"

terminal::terminal() {
    LOGGER.debug("terminal constructor start");

    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    orig_tty = tty;
    tty = setRawFlags(tty);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tty);

    LOGGER.debug("terminal constructor end");
}

terminal::~terminal() {
    LOGGER.debug("terminal destructor start");
    
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_tty);

    LOGGER.debug("terminal destructor end");
}

termios terminal::setRawFlags(struct termios tty) {
    LOGGER.debug("setRawFlags() start");
    tty.c_iflag &= ~(ICRNL | IXON);
    tty.c_oflag &= ~(OPOST);
    tty.c_lflag &= ~(ECHO | ICANON | IEXTEN);

    tty.c_cc[VSUSP] = _POSIX_VDISABLE; // Ctrl-Z

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tty);
    LOGGER.debug("setRawFlags() end");
    return tty;
}