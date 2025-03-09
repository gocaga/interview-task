#ifndef PACKET_VALIDATOR__H
#define PACKET_VALIDATOR__H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// #include "packets.h"
typedef enum
{
    VALID_PACKET,
    COMPLETE_PACKET,
    INCOMPLETE_PACKET,
    VALID_TYPE,
    INVALID_TYPE,
    VALID_SUBTYPE,
    INVALID_SUBTYPE,
    CORRECT_WRAPPER_CHECKSUM,
    INCORRECT_WRAPPER_CHECKSUM,
    INCORRECT_DATA_PORTION_CHECKSUM
}packet_validor_ErrorType_e;

// typedef struct 
// {
//     uint8_t packet[MAX_PACKET_LEN];
//     uint8_t size; 
// }packet_validator_obj;


packet_validor_ErrorType_e packet_validator_validateAsciiEncodedPacket(uint8_t packet[], uint8_t size);

#endif // PACKET_VALIDATOR__H