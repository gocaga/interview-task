#include "unity.h"
#include "packets.h"
#include "packet_validator.h"


void Packet_Validator_should_check_that_the_PACKET_is_more_than_four_characters_long(void)
{
    TEST_IGNORE_MESSAGE("Implement Me");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(Packet_Validator_should_check_that_the_PACKET_is_more_than_four_characters_long);
    RUN_TEST(Packet_Validator_should_check_that_the_first_character_of_the_PACKET_is_ANY_UPPERCASE_LETTER);
    RUN_TEST(Packet_Validator_should_check_that_the_second_character_of_the_PACKET_is_ANY_UPPERCASE_LETTER_or_number_0_to_9);
    RUN_TEST(Packet_Validator_should_check_that_the_wrapperChecksum_of_the_PACKET_is_calculated_as_per_requirement_1_1_1);
    RUN_TEST(Packet_Validator_should_check_that_the_one_chunk_of_dataPortion_of_PACKET_is_maximum_34_characters_including_the_chunkChecksum);
    RUN_TEST(Packet_Validator_should_check_that_the_one_chunk_of_dataPortion_of_PACKET_is_minimum_3_characters_including_the_chunkChecksum);
    RUN_TEST(Packet_Validator_should_check_that_the_preceding_final_chunk_of_dataPortion_of_PACKET_is_34_characters_including_the_chunkChecksum);
    RUN_TEST(Packet_Validator_should_check_that_the_final_chunk_of_dataPortion_of_PACKET_is_MIN_3_characters_and_MAX_34_chars_including_the_chunkChecksum);
    RUN_TEST(Packet_Validator_should_check_that_the_chunkChecksum_of_the_dataPortion_of_the_PACKET_is_calculated_as_per_requirement_1_2_1);
    RUN_TEST(Packet_Validator_should_check_for_an_EMPTY_dataPortion_of_the_PACKET);
    return UNITY_END();
}
