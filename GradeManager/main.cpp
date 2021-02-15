#include "Assignment.h"
#include "Course.h"

int main()
{
  Course compSci( "Computer Science" );

  compSci.addCategory( "Attendance", 10.0 );
  compSci.addCategory( "Participation", 5.0 );
  compSci.addCategory( "Knowledge Checks", 15.0 );
  compSci.addCategory( "Projects", 30.0 );
  compSci.addCategory( "Midterm", 20.0 );
  compSci.addCategory( "Final", 20.0 );

  Assignment homework( "Homework 1", 100.0, 100.0, "Homework" );
  Assignment project( "Project 1", 100.0, 100.0, "Project" );
  Assignment quiz( "Quiz 1", 10.0, 10.0, "Quiz" );
  Assignment something( "Something", 10.0, 10.0, "Participation" );

  compSci.addAssignment( homework );
  compSci.addAssignment( project );
  compSci.addAssignment( quiz );
  compSci.addAssignment( something );

  compSci.calcGrade();
}