#ifndef NBNSD_NBNS_H
#define NBNSD_NBNS_H

#include <stdint.h>

#define NBNS_PORT              137

#define NBNS_OPCODE_QUERY      0x0000

#define NBNS_FLAG_RESPONSE     0x8000
#define NBNS_FLAG_AUTHORITATIVE 0x0400
#define NBNS_FLAG_RECURSION_DESIRED 0x0100
#define NBNS_FLAG_RECURSION_AVAILABLE 0x0080

#define NBNS_RCODE_OK          0x0000

#define NBNS_TYPE_NB           0x0020
#define NBNS_CLASS_IN          0x0001

#pragma pack(push,1)

typedef struct
{
    uint16_t transaction_id;
    uint16_t flags;
    uint16_t question_count;
    uint16_t answer_count;
    uint16_t authority_count;
    uint16_t additional_count;
} nbns_header_t;

#pragma pack(pop)

typedef struct
{
    char name[17];

    uint16_t type;

    uint16_t class_id;

} nbns_question_t;

#endif