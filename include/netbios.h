#ifndef NETBIOS_H
#define NETBIOS_H

#include <stddef.h>
#include <stdint.h>

#define NETBIOS_NAME_LEN 16
#define NETBIOS_ENCODED_LEN 32

int netbios_decode_name(
    const uint8_t *encoded,
    char *decoded,
    size_t decoded_size);

int netbios_encode_name(
    const char *decoded,
    uint8_t *encoded,
    size_t encoded_size);

#endif