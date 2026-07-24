#ifndef NBNS_H
#define NBNS_H

#include <stddef.h>
#include <stdint.h>

#include "netbios.h"

#define NBNS_PORT 137

typedef struct
{
    uint16_t transaction_id;
    uint16_t flags;

    uint16_t questions;
    uint16_t answer_rrs;
    uint16_t authority_rrs;
    uint16_t additional_rrs;

} nbns_header_t;

int nbns_parse_header(
    const uint8_t *packet,
    size_t length,
    nbns_header_t *header);

#endif

typedef struct
{
    char name[NETBIOS_NAME_LEN + 1];
    uint16_t type;
    uint16_t class_id;

} nbns_question_t;

int nbns_parse_question(
    const uint8_t *packet,
    size_t length,
    size_t offset,
    nbns_question_t *question);