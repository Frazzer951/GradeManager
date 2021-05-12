#include <filesystem>
#include <iostream>
#include <string>

#include "Assignment.h"
#include "Course.h"
#include "Save.h"

void test()
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
  compSci.addAssignments( { participation, attendance, check_1, check_2, check_3, check_4, check_5, project_1, project_2, project_3, project_4, project_5, midterm, final } );

  // Calculate the grade
  compSci.calcGrade();

  saver::saveCourse( compSci );

  auto test = saver::loadCourse( "Computer Science.course" );

  test.calcGrade();
}

std::string toLowerStr( std::string str )
{
  for( int i = 0; i < str.size(); i++ )
  {
    str[i] = std::tolower( str[i] );
  }
  return str;
}

std::string get_user_input()
{
  std::cout << "\n\nPlease Enter one of the following options:\n"
            << "\t GetGrade:    Print out your current grade\n"
            << "\t AddAssign:   Add another Assignment \n"
            << "\t AddSection:  Add another Section \n"
            << "\t Quit:        Exit the program \n"
            << "Enter Choice: ";

  std::string user_input;
  std::getline( std::cin, user_input );
  return user_input;
}

int main()
{
  Course course;

  std::cout << "Would you like to load a course file, or start a new Course?\n";

  std::string input;
  while( true )
  {
    std::cout << "Enter 'Load' or 'New': ";
    std::getline( std::cin, input );

    if( input == "Load" || input == "load" )
    {
      // Get filename
      std::cout << "Please enter the filename of the course file: ";
      std::string filename = "";
      std::getline( std::cin, filename );

      if( !std::filesystem::exists( filename ) )
      {
        std::cout << "File not found! Try again\n";
        continue;
      }

      course = saver::loadCourse( filename );

      break;
    }
    else if( input == "New" || input == "new" )
    {
      // Start a new course

      std::cout << "Please enter the name of your course: ";
      std::getline( std::cin, input );

      course = Course( input );

      break;
    }
    else
    {
      std::cout << "Unknown Input!\n";
    }
  }

  while( true )
  {
    input = get_user_input();

    input = toLowerStr( input );

    if( input == "q" || input == "quit" )
    {
      break;
    }
  }
}