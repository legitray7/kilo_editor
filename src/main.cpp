#include <unistd.h>
#include <termios.h>

#include "terminal.h"
#include "logger.h"
using namespace std;

int main()
{
    logger log;
    log.log("main() start");
    terminal term;

    // turn terminal into raw mode
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        if (iscntrl(c)) {
            printf("%d\n", c);
        } else {
            printf("%d ('%c')\n", c, c);
        }
    }

    return 0;
}