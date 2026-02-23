#include <unistd.h>
#include <ncurses.h>

#include "terminal.h"
#include "util.h"

#include "config.h"

terminal::terminal() {
    LOGGER.debug("terminal constructor start");

    init_termios();
    init_screen();

    LOGGER.debug("terminal constructor end");
}

terminal::~terminal() {
    LOGGER.debug("terminal destructor start");
    
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_tty);
    restore_screen();

    LOGGER.debug("terminal destructor end");
}

int terminal::init_termios() {
    LOGGER.debug("init_termios() start");
    struct termios tty;
    if (tcgetattr(STDIN_FILENO, &tty) != 0) {
        LOGGER.error("tcgetattr() failure");
        exit(1);
    }
    // FOR restoring at end 
    orig_tty = tty;
    tty = set_flags(tty);
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tty) != 0) {
        LOGGER.error("tcsetattr() failure");
        exit(1);
    }

    LOGGER.debug("init_termios() end");
    return 0;
}

int terminal::init_screen() {
    LOGGER.debug("init_screen() start");

    LOGGER.debug("init_screen() end");
    return 0;
}

int terminal::restore_screen() {
    LOGGER.debug("restore_screen() start");

    LOGGER.debug("restore_screen() end");

    return 0;
}

termios terminal::set_flags(struct termios tty) {
    LOGGER.debug("set_flags() start");
    tty.c_iflag &= ~(           // disable
        IGNBRK | BRKINT |       // attr: BREAK
        INPCK | ISTRIP |        // attr: PARITY
        INLCR | IGNCR | ICRNL | // attr: CONVERT INPUT
        IXON                    // attr: FLOW CONTROL
    );
    tty.c_oflag &= ~(OPOST);
    tty.c_lflag &= ~(                    // disable
        ECHO | ECHOE | ECHOK | ECHOCTL | // attr: ECHO
        ICANON | IEXTEN | ISIG           // attr: SIGNALS
    );
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 0;

    LOGGER.debug("set_flags() end");
    return tty;
}