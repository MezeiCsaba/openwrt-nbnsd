#include "log.h"
#include "nbns.h"

int main(void)
{
    log_info("openwrt-nbnsd");
    log_info("NBNS port: %d", NBNS_PORT);
    return 0;
}