#include "netbios.h"

#include <string.h>

int netbios_decode_name(
    const uint8_t *encoded,
    char *decoded,
    size_t decoded_size)
{
    if (encoded == NULL || decoded == NULL)
        return -1;

    if (decoded_size < NETBIOS_NAME_LEN + 1)
        return -1;

    for (int i = 0; i < NETBIOS_NAME_LEN; i++)
    {
        uint8_t high = encoded[i * 2];
        uint8_t low  = encoded[i * 2 + 1];

        if (high < 'A' || high > 'P')
            return -1;

        if (low < 'A' || low > 'P')
            return -1;

        decoded[i] =
            ((high - 'A') << 4) |
            (low - 'A');
    }

    decoded[NETBIOS_NAME_LEN] = '\0';

    return 0;
}

int netbios_encode_name(
    const char *decoded,
    uint8_t *encoded,
    size_t encoded_size)
{
    if (decoded == NULL || encoded == NULL)
        return -1;

    if (encoded_size < NETBIOS_ENCODED_LEN)
        return -1;

    for (int i = 0; i < NETBIOS_NAME_LEN; i++)
    {
        uint8_t c = ' ';

        if ((size_t)i < strlen(decoded))
            c = (uint8_t)decoded[i];

        encoded[i * 2] =
            'A' + ((c >> 4) & 0x0F);

        encoded[i * 2 + 1] =
            'A' + (c & 0x0F);
    }

    return 0;
}