#include <gtest/gtest.h>

#include "Course.hpp"

class CourseTestsBase : public ::testing::Test
{
protected:
  void SetUp() override
  {
    course = Course( "Test Course" );
  }

  Course course;
};

// Name
TEST_F( CourseTestsBase, GetName )
{
  std::string returned_name = course.name();

  EXPECT_EQ( "Test Course", returned_name );
}

// Category
TEST_F( CourseTestsBase, AddCategory )
{
  std::map<std::string /*Category*/, double /*Weight*/> expected;
  expected["Test"]          = 100;
  expected["Uncategorized"] = 0;

  course.addCategory( "Test", 100 );
  auto result = course.categories();

  EXPECT_EQ( expected, result );
}

TEST_F( CourseTestsBase, RemoveCategory )
{
  std::map<std::string /*Category*/, double /*Weight*/> expected;
  expected["Uncategorized"] = 100;

  course.addCategory( "Test", 100 );
  course.removeCategory( "Test" );
  auto result = course.categories();

  EXPECT_EQ( expected, result );
}

TEST_F( CourseTestsBase, EditCategory )
{
  std::map<std::string /*Category*/, double /*Weight*/> expected;
  expected["Test"]          = 75;
  expected["Uncategorized"] = 25;

  course.addCategory( "Test", 100 );
  course.editCategory( "Test", 75 );
  auto result = course.categories();

  EXPECT_EQ( expected, result );
}

// Assignment
TEST_F( CourseTestsBase, AddAssignment )
{
  std::map<std::string /*Name    */, Assignment> expected;

  Assignment assign( "Test", 10, 10, "Cat" );
  expected[assign.name()] = assign;

  course.addAssignment( assign );
  auto result = course.assignments();

  EXPECT_EQ( expected, result );
}

TEST_F( CourseTestsBase, AddAssignments )
{
  std::map<std::string /*Name    */, Assignment> expected;

  Assignment assign_1( "Test_1", 10, 10, "Cat_1" );
  Assignment assign_2( "Test_2", 5, 20, "Cat_2" );
  expected[assign_1.name()] = assign_1;
  expected[assign_2.name()] = assign_2;

  course.addAssignments( { assign_1, assign_2 } );
  auto result = course.assignments();

  EXPECT_EQ( expected, result );
}

TEST_F( CourseTestsBase, RemoveAssignment )
{
  std::map<std::string /*Name    */, Assignment> expected;

  Assignment assign_1( "Test_1", 10, 10, "Cat_1" );
  Assignment assign_2( "Test_2", 5, 20, "Cat_2" );
  expected[assign_1.name()] = assign_1;

  course.addAssignments( { assign_1, assign_2 } );
  course.removeAssignment( "Test_2" );
  auto result = course.assignments();

  EXPECT_EQ( expected, result );
}

// Calculate Uncategorized
TEST_F( CourseTestsBase, CalcUncategorized )
{
  course.addCategory( "Test", 100 );
  auto result = course.categories();
  EXPECT_DOUBLE_EQ( 0.0, result["Uncategorized"] );

  course.editCategory( "Test", 75 );
  result = course.categories();
  EXPECT_DOUBLE_EQ( 25.0, result["Uncategorized"] );

  course.editCategory( "Test", 50 );
  result = course.categories();
  EXPECT_DOUBLE_EQ( 50.0, result["Uncategorized"] );

  course.editCategory( "Test", 13.8 );
  result = course.categories();
  EXPECT_DOUBLE_EQ( 86.2, result["Uncategorized"] );
}