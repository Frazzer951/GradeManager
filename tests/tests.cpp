#include <gtest/gtest.h>

#include "Assignment.hpp"

class AssignmentTests : public ::testing::Test
{
protected:
  void SetUp() override
  {
    assign = Assignment( "Test", 100.0, 100.0, "Test Cat" );
  }

  Assignment assign;
};

// Name
TEST_F( AssignmentTests, GetName )
{
  std::string returned_name = assign.name();

  EXPECT_EQ( "Test", returned_name );
}

TEST_F( AssignmentTests, SetName )
{
  assign.name( "New Name" );
  std::string returned_name = assign.name();

  EXPECT_EQ( "New Name", returned_name );
}

// Category
TEST_F( AssignmentTests, GetCategory )
{
  std::string returned_category = assign.category();

  EXPECT_EQ( "Test Cat", returned_category );
}

TEST_F( AssignmentTests, SetCategory )
{
  assign.category( "New Cat" );
  std::string returned_category = assign.category();

  EXPECT_EQ( "New Cat", returned_category );
}

// Score
TEST_F( AssignmentTests, GetScore )
{
  double returned_Score = assign.score();

  EXPECT_DOUBLE_EQ( 100.0, returned_Score );
}

TEST_F( AssignmentTests, SetScore )
{
  assign.score( 80.0 );
  double returned_Score = assign.score();

  EXPECT_DOUBLE_EQ( 80.0, returned_Score );
}

// Max Score
TEST_F( AssignmentTests, GetMaxScore )
{
  double returned_MaxScore = assign.maxScore();

  EXPECT_DOUBLE_EQ( 100.0, returned_MaxScore );
}

TEST_F( AssignmentTests, SetMaxScore )
{
  assign.maxScore( 180.0 );
  double returned_MaxScore = assign.maxScore();

  EXPECT_DOUBLE_EQ( 180.0, returned_MaxScore );
}

// Test Printing of Assignment
TEST_F( AssignmentTests, ShiftLeftOperator )
{
  std::ostringstream output;

  output << assign;

  EXPECT_EQ( "Test, 100/100", output.str() );
}

