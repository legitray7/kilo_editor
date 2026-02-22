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
    tty.c_iflag &= ~(
        IGNBRK | BRKINT |       // BREAK
        INPCK | ISTRIP |        // PARITY
        INLCR | IGNCR | ICRNL | // CONVERT INPUT
        IXON                    // FLOW CONTROL
    );
    tty.c_oflag &= ~(OPOST);
    tty.c_lflag &= ~(
        ECHO | ECHOE | ECHOK | ECHOCTL |
        ICANON | IEXTEN | ISIG
    );
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 0;

    tty.c_cc[VSUSP] = _POSIX_VDISABLE; // Ctrl-Z

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tty);
    LOGGER.debug("setRawFlags() end");
    return tty;
}