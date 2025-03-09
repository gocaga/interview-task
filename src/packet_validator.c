#include "packet_validator.h"


packet_validor_ErrorType_e packet_validator_validateAsciiEncodedPacket(uint8_t packet[], uint8_t size)
{
    uint8_t calculated_wrapper_checksum = 0;
    if((size - 1) < 4) //Factoring the null terminator of the array
    {
        return INCOMPLETE_PACKET /*COMPLETE_PACKET*/;
    }
    // else
    // {
    //     return INCOMPLETE_PACKET;
    // }

    if((!(packet[0] >= 'A' && packet[0] <= 'Z')))
        return INVALID_TYPE /*VALID_TYPE*/;
    // else
    //     return INVALID_TYPE;

    if(!((packet[1] >= 'A' && packet[1] <= 'Z') || (packet[1] >= '0' && packet[1] <= '9')))
        return INVALID_SUBTYPE;
    // else
    //     return INVALID_SUBTYPE;


    calculated_wrapper_checksum = (packet[0] + packet[1]) % 256;


    uint8_t wrapper_checksum_hex[3];
    wrapper_checksum_hex[0] = packet[size - 3];
    wrapper_checksum_hex[1] = packet[size - 2];
    wrapper_checksum_hex[2] = '\0' ;

    long int wrapper_checksum_deci = strtol(wrapper_checksum_hex, NULL, 16);

                                                      

    if(wrapper_checksum_deci == calculated_wrapper_checksum)
        return CORRECT_WRAPPER_CHECKSUM;
    else
        return INCORRECT_WRAPPER_CHECKSUM;

     
}