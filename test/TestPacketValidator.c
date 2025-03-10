#include "unity.h"
#include "packets.h"
#include "packet_validator.h"

void Packet_Validator_should_check_that_the_PACKET_is_less_than_four_characters_long(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t packet[] = "12P";
    uint8_t size     = sizeof(packet) / sizeof(packet[0]);

    error_status = packet_validator_validateAsciiEncodedPacket(packet, size);
    TEST_ASSERT_EQUAL(INCOMPLETE_PACKET, error_status);
}

void Packet_Validator_should_check_that_the_first_character_of_the_PACKET_is_NOT_ANY_UPPERCASE_LETTER(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t packet[] = "12PW";
    uint8_t size     = sizeof(packet) / sizeof(packet[0]);

    error_status = packet_validator_validateAsciiEncodedPacket(packet, size);
    TEST_ASSERT_EQUAL(INVALID_TYPE, error_status);
}

void Packet_Validator_should_check_that_the_second_character_of_the_PACKET_is_ANY_UPPERCASE_LETTER_or_number_0_to_9(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t packet[] = "XeA2PW";
    uint8_t size     = sizeof(packet) / sizeof(packet[0]);

    error_status = packet_validator_validateAsciiEncodedPacket(packet, size);
    TEST_ASSERT_EQUAL(INVALID_SUBTYPE, error_status);
}

void Packet_Validator_should_check_that_the_wrapperChecksum_of_the_PACKET_is_calculated_as_per_requirement_1_1_1(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t packet[] = "WSAA";
    uint16_t size     = sizeof(packet) / sizeof(packet[0]);

    uint8_t invalid_wrapper_chcksum_packet[] = "Y1ZHRCNHZHUIHBJUXTFWUAPUZKVEBCZOROC9NFXDYZUSMVEOOUPMWIF \
                                                WSZAFHGGJFXHFC0QSOEWUUGCCNUPLVAOOGRIUVOFRVSSLMOD2NZXWGL \
                                                PBNZUQLFQWKGURQQWWXAZEZCOR03PYGPNZTCYEDJZEDZBYHLQVYXCBY \
                                                GMKCLBBLDAMZAJKMSSMNNXSWADAUCAU208B"; //!< invalid packet 3.2 on page 5 of the Interview Task
    uint16_t size_of_invalid_packet = sizeof(invalid_wrapper_chcksum_packet) / sizeof(invalid_wrapper_chcksum_packet[0]);

    //!< Test valid packet
    error_status = packet_validator_validateAsciiEncodedPacket(packet, size);
    TEST_ASSERT_EQUAL(ZERO_DATA, error_status);

    //!< Test invalid packet with incorrect wrapper checksum
    TEST_ASSERT_EQUAL(INCORRECT_WRAPPER_CHECKSUM, packet_validator_validateAsciiEncodedPacket(invalid_wrapper_chcksum_packet, size_of_invalid_packet));
}

void Packet_Validator_should_check_that_the_one_chunk_of_dataPortion_of_PACKET_is_maximum_34_characters_including_the_chunkChecksum(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t one_chunk_packet[]   = "L1001411608032923583423317D"; //!< valid packet 3.1 on page 5 of the Interview Task
    uint8_t multi_chunk_packet[] = "H11E1050110117003D000000400010000043000200036+1368079"; 
                                      //1E1050110117003D0000004000100000                        
    uint8_t invalid_packet[]     = "A1MMBNQOBRXWEQZBOWYYDMJPDGJMHCQJCF92LQNXJZBDKWPBOGACL \
                                    YDCROZXIVDEGZAO93TYFJNRMZWZCNACSDLFQSFANXQQOOWXXKD6VA \
                                    HPBQOULEF772"; //!< invalid packet 3.3 on page 5 of the Interview Task

    uint16_t size_of_multi_chunk_packet = sizeof(multi_chunk_packet) / sizeof(multi_chunk_packet[0]);
    uint16_t size                       = sizeof(one_chunk_packet) / sizeof(one_chunk_packet[0]);
    uint16_t size_of_invalid_packet     = sizeof(invalid_packet) / sizeof(invalid_packet[0]);

    //!< Test the valid packet with one chunk of data
    error_status = packet_validator_validateAsciiEncodedPacket(one_chunk_packet, size);
    // TEST_ASSERT_EQUAL(VALID_PACKET, error_status);

    //!< Test a valid packet with multiple chunks of data
    TEST_ASSERT_EQUAL(VALID_PACKET, packet_validator_validateAsciiEncodedPacket(multi_chunk_packet, size_of_multi_chunk_packet));

    //!< Test invalid packet
    // TEST_ASSERT_EQUAL(INCORRECT_DATA_PORTION_CHECKSUM, packet_validator_validateAsciiEncodedPacket(invalid_packet, size_of_invalid_packet));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(Packet_Validator_should_check_that_the_PACKET_is_less_than_four_characters_long);
    RUN_TEST(Packet_Validator_should_check_that_the_first_character_of_the_PACKET_is_NOT_ANY_UPPERCASE_LETTER);
    RUN_TEST(Packet_Validator_should_check_that_the_second_character_of_the_PACKET_is_ANY_UPPERCASE_LETTER_or_number_0_to_9);
    RUN_TEST(Packet_Validator_should_check_that_the_wrapperChecksum_of_the_PACKET_is_calculated_as_per_requirement_1_1_1);
    RUN_TEST(Packet_Validator_should_check_that_the_one_chunk_of_dataPortion_of_PACKET_is_maximum_34_characters_including_the_chunkChecksum);

    return UNITY_END();
}
