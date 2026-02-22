#include <unistd.h>
#include <termios.h>

#include "terminal.h"
#include "logger.h"
#include "key.h"
using namespace std;

int main()
{
    LOGGER.debug("main() start");
    terminal term;
    while (1) {
        // turn terminal into raw mode
        char c;
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) {
            LOGGER.error("cannot read input");
            return -1;
        }

        if (iscntrl(c)) {
            printf("%d\r\n", c);
        } else {
            printf("%d ('%c')\r\n", c, c);
        }
        if (c == CTRL_KEY('q')) break;
    }
    
    LOGGER.debug("main() end");
    return 0;
}