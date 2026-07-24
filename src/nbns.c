#include "nbns.h"

#include "netbios.h"

#include <string.h>

static uint16_t read_u16(const uint8_t *p)
{
    return ((uint16_t)p[0] << 8) | p[1];
}

int nbns_parse_header(
    const uint8_t *packet,
    size_t length,
    nbns_header_t *header)
{
    if (packet == NULL || header == NULL)
        return -1;

    if (length < 12)
        return -1;

    header->transaction_id = read_u16(packet + 0);
    header->flags          = read_u16(packet + 2);

    header->questions      = read_u16(packet + 4);
    header->answer_rrs     = read_u16(packet + 6);
    header->authority_rrs  = read_u16(packet + 8);
    header->additional_rrs = read_u16(packet + 10);

    return 0;
}

int nbns_parse_question(
    const uint8_t *packet,
    size_t length,
    size_t offset,
    nbns_question_t *question)
{
    if (packet == NULL || question == NULL)
        return -1;

    if (offset + 34 + 4 > length)
        return -1;

    uint8_t encoded[NETBIOS_ENCODED_LEN];

    memcpy(encoded, packet + offset + 1, NETBIOS_ENCODED_LEN);

    if (netbios_decode_name(
            encoded,
            question->name,
            sizeof(question->name)))
    {
        return -1;
    }

    question->type =
        read_u16(packet + offset + 33);

    question->class_id =
        read_u16(packet + offset + 35);

    return 0;
}