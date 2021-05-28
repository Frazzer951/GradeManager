#include <gtest/gtest.h>

#include "Save.hpp"

class SaveLoadTest : public ::testing::Test
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

TEST_F( SaveLoadTest, SaveLoad )
{
  saver::saveCourse( course, "test" );
  Course loaded_course = saver::loadCourse( "test.json" );

  EXPECT_EQ( course, loaded_course );
}