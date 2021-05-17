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

class CourseTestsFull : public ::testing::Test
{
protected:
  void SetUp() override
  {
    course = Course( "Test Course" );

    // Create Categories
    course.addCategory( "Attendance", 10.0 );
    course.addCategory( "Participation", 5.0 );
    course.addCategory( "Knowledge Checks", 15.0 );
    course.addCategory( "Projects", 30.0 );
    course.addCategory( "Midterm", 20.0 );
    course.addCategory( "Final", 20.0 );

    // Make Assignments
    Assignment participation( "Participation", 100.0, 100.0, "Participation" );
    Assignment attendance( "Attendance", 95.0, 100.0, "Attendance" );
    Assignment check_1( "Knowledge Check 1", 18.0, 20.0, "Knowledge Checks" );
    Assignment check_2( "Knowledge Check 2", 16.8, 20.0, "Knowledge Checks" );
    Assignment check_3( "Knowledge Check 3", 19.9, 20.0, "Knowledge Checks" );
    Assignment check_4( "Knowledge Check 4", 20.0, 20.0, "Knowledge Checks" );
    Assignment check_5( "Knowledge Check 5", 18.4, 20.0, "Knowledge Checks" );
    Assignment project_1( "Project 1", 100.0, 100.0, "Projects" );
    Assignment project_2( "Project 2", 98.1, 100.0, "Projects" );
    Assignment project_3( "Project 3", 75.0, 100.0, "Projects" );
    Assignment project_4( "Project 4", 99.9, 100.0, "Projects" );
    Assignment project_5( "Project 5", 100.0, 100.0, "Projects" );
    Assignment midterm( "Midterm", 100.0, 100.0, "Midterm" );
    Assignment final( "Final", 105.0, 100.0, "Final" );

    // Add Assignments
    course.addAssignments( { participation, attendance, check_1, check_2, check_3, check_4, check_5, project_1, project_2, project_3, project_4, project_5, midterm, final } );
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
  Assignment                                     assign( "Test", 10, 10, "Cat" );
  expected[assign.name()] = assign;

  course.addAssignment( assign );
  auto result = course.assignments();

  //EXPECT_EQ( expected, result );
}

TEST_F( CourseTestsBase, AddAssignments )
{
}


TEST_F( CourseTestsBase, RemoveAssignment )
{
}