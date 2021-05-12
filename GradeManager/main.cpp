#include "Assignment.h"
#include "Course.h"
#include "Save.h"

int main()
{
  // Create Course
  Course compSci( "Computer Science" );

  // Create Categories
  compSci.addCategory( "Attendance", 10.0 );
  compSci.addCategory( "Participation", 5.0 );
  compSci.addCategory( "Knowledge Checks", 15.0 );
  compSci.addCategory( "Projects", 30.0 );
  compSci.addCategory( "Midterm", 20.0 );
  compSci.addCategory( "Final", 20.0 );

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
  //compSci.addAssignment( participation );
  //compSci.addAssignment( attendance );
  //compSci.addAssignment( check_1 );
  //compSci.addAssignment( check_2 );
  //compSci.addAssignment( check_3 );
  //compSci.addAssignment( check_4 );
  //compSci.addAssignment( check_5 );
  //compSci.addAssignment( project_1 );
  //compSci.addAssignment( project_2 );
  //compSci.addAssignment( project_3 );
  //compSci.addAssignment( project_4 );
  //compSci.addAssignment( project_5 );
  //compSci.addAssignment( midterm );
  //compSci.addAssignment( final );
  compSci.addAssignments( { participation, attendance, check_1, check_2, check_3, check_4, check_5, project_1, project_2, project_3, project_4, project_5, midterm, final } );

  // Calculate the grade
  compSci.calcGrade();

  saver::saveCourse( compSci );

  auto test = saver::loadCourse( "Computer Science.course" );

  test.calcGrade();
}