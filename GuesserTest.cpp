/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

TEST(GuesserTest, BigDistanceWrongGuessLockOut) {
  Guesser g("hello");
  ASSERT_FALSE(g.match("abcde"));
  ASSERT_FALSE(g.match("hello"));
  ASSERT_EQ(3, g.remaining());
}

TEST(GuesserTest, LockedAfterThreeWrongDistanceGuesses) {
  Guesser g("flame");

  g.match("frame");
  g.match("flume");
  g.match("frame");

  ASSERT_FALSE(g.match("flame"));
  ASSERT_EQ(0, g.remaining());
}

TEST(GuesserTest, ExactMatchDistanceIsZero) {
  Guesser g("test");
  ASSERT_TRUE(g.match("test"));
  ASSERT_EQ(g.remaining(), 3);
}

TEST(GuesserTest, Distance2GuessDecrementsRemaining) {
  Guesser g("abc");
  ASSERT_FALSE(g.match("acc"));
  ASSERT_FALSE(g.match("aax"));
  ASSERT_EQ(g.remaining(), 1);
}

TEST(GuesserTest, Distance1GuessDecrementsRemaining) {
  Guesser g("abc");
  ASSERT_FALSE(g.match("abd"));
  ASSERT_EQ(g.remaining(), 2);
}
