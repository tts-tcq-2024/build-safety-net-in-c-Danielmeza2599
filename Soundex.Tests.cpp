//#include <gtest/gtest.h>
//#include "Soundex.h"

//TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  //char soundex[5];
  //generateSoundex("AX", soundex);
 // ASSERT_EQ(soundex,"A200");
//}


// Daniel Meza Changes  SOUNDX TEST
//The refactoring task
	///• Cyclomatic complexity is high in a few places. 
 //This indicates potential to steadily increase, as customers ask for changes and new features. 
 //Reduce the cyclomatic complexity. In future, it must be possible to add new features with less code-changes and 
//re-testing.
	///• Code coverage is low, because the test code is incomplete. Write more tests to take care of the variations. 
 //Track and improve the coverage.
//Uncovered lines indicate an opportunity to write tests. Complex and repetitive tests 
//indicate opportunity to simplify the code.

#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestSuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];

    // Try for the first letter and consonants
    generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A200");

    generateSoundex("BCDF", soundex);
    ASSERT_STREQ(soundex, "B231");

    generateSoundex("HJLM", soundex);
    ASSERT_STREQ(soundex, "H245");

    generateSoundex("PQRS", soundex);
    ASSERT_STREQ(soundex, "P262");

    generateSoundex("TVWX", soundex);
    ASSERT_STREQ(soundex, "T125");
}

TEST(SoundexTestSuite, IgnoresVowelsAndCertainLetters) {
    char soundex[5];

    generateSoundex("AEIOU", soundex);
    ASSERT_STREQ(soundex, "A000");

    generateSoundex("HWY", soundex);
    ASSERT_STREQ(soundex, "H000");

    generateSoundex("AHYW", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestSuite, HandlesRepeatedLetters) {
    char soundex[5];

    generateSoundex("BBBB", soundex);
    ASSERT_STREQ(soundex, "B100");

    generateSoundex("LLL", soundex);
    ASSERT_STREQ(soundex, "L400");

    generateSoundex("MMNN", soundex);
    ASSERT_STREQ(soundex, "M550");
}

TEST(SoundexTestSuite, PadsWithZerosIfNecessary) {
    char soundex[5];

    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");

    generateSoundex("Ab", soundex);
    ASSERT_STREQ(soundex, "A100");

    generateSoundex("Abc", soundex);
    ASSERT_STREQ(soundex, "A120");
}

TEST(SoundexTestSuite, HandlesDifferentLengths) {
    char soundex[5];

    generateSoundex("Abcd", soundex);
    ASSERT_STREQ(soundex, "A123");

    generateSoundex("Abcde", soundex);
    ASSERT_STREQ(soundex, "A123");

    generateSoundex("Abcdefg", soundex);
    ASSERT_STREQ(soundex, "A123");
}

TEST(SoundexTestSuite, HandlesSpecialCharactersAndSpaces) {
    char soundex[5];

    generateSoundex("A b", soundex);
    ASSERT_STREQ(soundex, "A100");

    generateSoundex("A-b", soundex);
    ASSERT_STREQ(soundex, "A100");

    generateSoundex("A1b", soundex);
    ASSERT_STREQ(soundex, "A100");
}

TEST(SoundexTestSuite, HandlesMixedCase) {
    char soundex[5];

    generateSoundex("aBcD", soundex);
    ASSERT_STREQ(soundex, "A123");

    generateSoundex("AbCd", soundex);
    ASSERT_STREQ(soundex, "A123");

    generateSoundex("ABcD", soundex);
    ASSERT_STREQ(soundex, "A123");
}
