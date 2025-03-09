#include "unity.h"
#include "packets.h"
#include "packet_validator.h"


// void Packet_Validator_should_check_that_the_PACKET_is_more_than_four_characters_long(void)
// {
//     packet_validor_ErrorType_e error_status;

//     uint8_t packet[] = "125W";
//     uint8_t size     = sizeof(packet) / sizeof(packet[0]);

//     error_status = packet_validator_validateAsciiEncodedPacket(packet,size);
//     TEST_ASSERT_EQUAL(COMPLETE_PACKET, error_status);

// }

void Packet_Validator_should_check_that_the_PACKET_is_less_than_four_characters_long(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t packet[] = "12P";
    uint8_t size     = sizeof(packet) / sizeof(packet[0]);

    error_status = packet_validator_validateAsciiEncodedPacket(packet,size);
    TEST_ASSERT_EQUAL(INCOMPLETE_PACKET, error_status);

}

// void Packet_Validator_should_check_that_the_first_character_of_the_PACKET_is_ANY_UPPERCASE_LETTER(void)
// {
//     packet_validor_ErrorType_e error_status;

//     uint8_t packet0[] = "W12PW";
//     uint8_t size0     = sizeof(packet0) / sizeof(packet0[0]);

//     uint8_t packet1[] = "A12PW";
//     uint8_t size1     = sizeof(packet1) / sizeof(packet1[0]);


//     uint8_t packet2[] = "D12PW";
//     uint8_t size2     = sizeof(packet2) / sizeof(packet2[0]);

//     uint8_t packet3[] = "X12PW";
//     uint8_t size3     = sizeof(packet3) / sizeof(packet3[0]);

//     error_status = packet_validator_validateAsciiEncodedPacket(packet0, size0);
//     TEST_ASSERT_EQUAL(VALID_TYPE, error_status);

//     error_status = packet_validator_validateAsciiEncodedPacket(packet1, size1);
//     TEST_ASSERT_EQUAL(VALID_TYPE, error_status);

//     error_status = packet_validator_validateAsciiEncodedPacket(packet2, size2);
//     TEST_ASSERT_EQUAL(VALID_TYPE, error_status);

//     error_status = packet_validator_validateAsciiEncodedPacket(packet3, size3);
//     TEST_ASSERT_EQUAL(VALID_TYPE, error_status);

// }

void Packet_Validator_should_check_that_the_first_character_of_the_PACKET_is_NOT_ANY_UPPERCASE_LETTER(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t packet[] = "12PW";
    uint8_t size     = sizeof(packet) / sizeof(packet[0]);

    error_status = packet_validator_validateAsciiEncodedPacket(packet,size);
    TEST_ASSERT_EQUAL(INVALID_TYPE, error_status);

}

void Packet_Validator_should_check_that_the_second_character_of_the_PACKET_is_ANY_UPPERCASE_LETTER_or_number_0_to_9(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t packet[] = "XeA2PW";
    uint8_t size     = sizeof(packet) / sizeof(packet[0]);

    error_status = packet_validator_validateAsciiEncodedPacket(packet,size);
    TEST_ASSERT_EQUAL(INVALID_SUBTYPE, error_status);

    // TEST_IGNORE_MESSAGE("Implement Me");
}

void Packet_Validator_should_check_that_the_wrapperChecksum_of_the_PACKET_is_calculated_as_per_requirement_1_1_1(void)
{
    packet_validor_ErrorType_e error_status;

    uint8_t packet[] = "WSAA";
    uint8_t size     = sizeof(packet) / sizeof(packet[0]);

    error_status = packet_validator_validateAsciiEncodedPacket(packet,size);
    TEST_ASSERT_EQUAL(CORRECT_WRAPPER_CHECKSUM, error_status);

    // TEST_ASSERT_EQUAL(packet[3], error_status);
    // TEST_IGNORE_MESSAGE("Implement Me");
}
int main(void) {
    UNITY_BEGIN();
    // RUN_TEST(Packet_Validator_should_check_that_the_PACKET_is_more_than_four_characters_long);
    RUN_TEST(Packet_Validator_should_check_that_the_PACKET_is_less_than_four_characters_long);
    // RUN_TEST(Packet_Validator_should_check_that_the_first_character_of_the_PACKET_is_ANY_UPPERCASE_LETTER);
    RUN_TEST(Packet_Validator_should_check_that_the_first_character_of_the_PACKET_is_NOT_ANY_UPPERCASE_LETTER);
    RUN_TEST(Packet_Validator_should_check_that_the_second_character_of_the_PACKET_is_ANY_UPPERCASE_LETTER_or_number_0_to_9);
    RUN_TEST(Packet_Validator_should_check_that_the_wrapperChecksum_of_the_PACKET_is_calculated_as_per_requirement_1_1_1);
    // RUN_TEST(Packet_Validator_should_check_that_the_one_chunk_of_dataPortion_of_PACKET_is_maximum_34_characters_including_the_chunkChecksum);
    // RUN_TEST(Packet_Validator_should_check_that_the_one_chunk_of_dataPortion_of_PACKET_is_minimum_3_characters_including_the_chunkChecksum);
    // RUN_TEST(Packet_Validator_should_check_that_the_preceding_final_chunk_of_dataPortion_of_PACKET_is_34_characters_including_the_chunkChecksum);
    // RUN_TEST(Packet_Validator_should_check_that_the_final_chunk_of_dataPortion_of_PACKET_is_MIN_3_characters_and_MAX_34_chars_including_the_chunkChecksum);
    // RUN_TEST(Packet_Validator_should_check_that_the_chunkChecksum_of_the_dataPortion_of_the_PACKET_is_calculated_as_per_requirement_1_2_1);
    // RUN_TEST(Packet_Validator_should_check_for_an_EMPTY_dataPortion_of_the_PACKET);
    return UNITY_END();
}
