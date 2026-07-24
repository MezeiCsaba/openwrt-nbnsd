#include <stdio.h>
#include <stdint.h>

#include "nbns.h"

int main(void)
{
    const uint8_t packet[] =
    {
        0xFD,0x59,
        0x01,0x10,
        0x00,0x01,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00
    };

    nbns_header_t h;

    if (nbns_parse_header(packet, sizeof(packet), &h))
    {
        printf("Parse FAILED\n");
        return 1;
    }

    printf("Transaction ID : %04X\n", h.transaction_id);
    printf("Flags          : %04X\n", h.flags);
    printf("Questions      : %u\n", h.questions);

    if (h.transaction_id != 0xFD59)
        return 1;

    if (h.flags != 0x0110)
        return 1;

    if (h.questions != 1)
        return 1;

    printf("PASS\n");

    return 0;
}