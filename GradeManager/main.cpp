#include "Assignment.h"
#include "Course.h"

int main()
{
  Course compSci( "Computer Science" );

  compSci.addCategory( "Homework", 20.0 );
  compSci.addCategory( "Project", 30.0 );
  compSci.addCategory( "Quiz", 40.0 );

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