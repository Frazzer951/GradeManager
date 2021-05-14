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

Course get_Course()
{
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

      return saver::loadCourse( filename );

      break;
    }
    else if( input == "New" || input == "new" )
    {
      // Start a new course

      std::cout << "Please enter the name of your course: ";
      std::getline( std::cin, input );

      return Course( input );

      break;
    }
    else
    {
      std::cout << "Unknown Input!\n";
    }
  }
}

std::string get_main_menu()
{
  std::cout << "\n\n1. Save Course\n"
            << "2. Get Grade\n"
            << "3. Manage Assignments\n"
            << "4. Manage Sections\n"
            << "5. Quit\n"
            << "Enter Number for Choice: ";

  std::string user_input;
  std::getline( std::cin, user_input );
  return user_input;
}

std::string get_assignment_menu()
{
  std::cout << "\n\n1. Add Assignment\n"
            << "2. Remove Assignment\n"
            << "3. Edit Assignment\n"
            << "4. Return to main menu\n"
            << "Enter Number for Choice: ";

  std::string user_input;
  std::getline( std::cin, user_input );
  return user_input;
}

std::string get_section_menu()
{
  std::cout << "\n\n1. Add Section\n"
            << "2. Remove Section\n"
            << "3. Edit Section\n"
            << "4. Return to main menu\n"
            << "Enter Number for Choice: ";

  std::string user_input;
  std::getline( std::cin, user_input );
  return user_input;
}

void assignment_menu( Course & course )
{
  std::string input;
  while( true )
  {
    // List out menu
    // Get Input
    input = get_assignment_menu();
    std::cout << "\n";
    if( input == "1" )
    {
      // Add Assignment
    }
    else if( input == "2" )
    {
      // Remove Assignment
    }
    else if( input == "3" )
    {
      // Edit Assignment
    }
    else if( input == "4" || input == "q" || input == "quit" || input == "Quit" )
    {
      return;
    }
    else
    {
      std::cout << "Unknown Input!\n";
    }
  }
}

void section_menu( Course & course )
{
  std::string input;
  while( true )
  {
    // List out menu
    // Get Input
    input = get_section_menu();
    std::cout << "\n";
    if( input == "1" )
    {
      // Add Section
    }
    else if( input == "2" )
    {
      // Remove Section
    }
    else if( input == "3" )
    {
      // Edit Section
    }
    else if( input == "4" || input == "q" || input == "quit" || input == "Quit" )
    {
      return;
    }
    else
    {
      std::cout << "Unknown Input!\n";
    }
  }
}

void user_input_handler( Course & course )
{
  std::string input;
  while( true )
  {
    // List out main menu
    // Get Input
    input = get_main_menu();
    std::cout << "\n";
    if( input == "1" )
    {
      // Please enter a filename
      // Save File with filename
      std::cout << "Enter the desired filename: ";
      std::getline( std::cin, input );

      saver::saveCourse( course, input );
    }
    else if( input == "2" )
    {
      course.calcGrade();
    }
    else if( input == "3" )
    {
      // Go into Assignment Menu
      assignment_menu( course );
    }
    else if( input == "4" )
    {
      // Go into Section Menu
      section_menu( course );
    }
    else if( input == "5" || input == "q" || input == "quit" || input == "Quit" )
    {
      return;
    }
    else
    {
      std::cout << "Unknown Input!\n";
    }
  }
}

int main()
{
  Course course = get_Course();

  user_input_handler( course );
}