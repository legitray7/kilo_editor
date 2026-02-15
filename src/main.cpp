#include <termios.h>
#include "logging.h"
using namespace std;

int main()
{
    Logger logger;
    // turn terminal into raw mode
    logger.debug("test");
    logger.error("test");
    logger.log("test");
}