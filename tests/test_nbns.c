#include <stdio.h>
#include <stdint.h>

#include "nbns.h"

int main(void)
{
    /*
     * NBNS header + Question
     * A Question mező a korábban rögzített kamera forgalomból származik.
     */
    const uint8_t packet[] =
    {
        /* Header */
        0xFD,0x59,
        0x01,0x10,
        0x00,0x01,
        0x00,0x00,
        0x00,0x00,
        0x00,0x00,

        /* Question */

        0x20,

        'C','K','A','A','A','A','A','A',
        'A','A','A','A','A','A','A','A',
        'A','A','A','A','A','A','A','A',
        'A','A','A','A','A','A','A','A',

        0x00,

        0x00,0x20,
        0x00,0x01
    };

    nbns_header_t header;
    nbns_question_t question;

    if (nbns_parse_header(packet, sizeof(packet), &header))
    {
        printf("Header parse FAILED\n");
        return 1;
    }

    if (nbns_parse_question(packet,
                            sizeof(packet),
                            12,
                            &question))
    {
        printf("Question parse FAILED\n");
        return 1;
    }

    printf("Transaction ID : %04X\n", header.transaction_id);
    printf("Flags          : %04X\n", header.flags);
    printf("Questions      : %u\n", header.questions);

    printf("Name           : '%s'\n", question.name);
    printf("Type           : %04X\n", question.type);
    printf("Class          : %04X\n", question.class_id);

    if (header.transaction_id != 0xFD59)
        return 1;

    if (question.type != 0x0020)
        return 1;

    if (question.class_id != 0x0001)
        return 1;

    printf("PASS\n");

    return 0;
}