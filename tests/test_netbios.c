#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "netbios.h"

int main(void)
{
    const char original[] = "FRED";

    uint8_t encoded[NETBIOS_ENCODED_LEN];
    char decoded[NETBIOS_NAME_LEN + 1];

    if (netbios_encode_name(original, encoded, sizeof(encoded)) != 0)
    {
        printf("Encode FAILED\n");
        return 1;
    }

    if (netbios_decode_name(encoded, decoded, sizeof(decoded)) != 0)
    {
        printf("Decode FAILED\n");
        return 1;
    }

    printf("Original : '%s'\n", original);
    printf("Decoded  : '%s'\n", decoded);

    if (strncmp(original, decoded, strlen(original)) != 0)
    {
        printf("Round-trip FAILED\n");
        return 1;
    }

    printf("PASS\n");

    return 0;
}