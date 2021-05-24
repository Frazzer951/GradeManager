#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Assignment.hpp"
#include "Course.hpp"
#include "FMenu.hpp"
#include "Save.hpp"

Course course;

void loadCourse()
{
  while( true )
  {
    std::string filename;

    std::cout << "Please enter the filename of the course file: ";
    std::getline( std::cin, filename );

    if( !std::filesystem::exists( filename ) )
    {
      std::cout << "File not found! Try again\n";
      continue;
    }

    course = saver::loadCourse( filename );
    break;
  }
}

void save()
{
  std::string filename;

  std::cout << "Enter the desired filename: ";
  std::getline( std::cin, filename );

  saver::saveCourse( course, filename );
}

void newCourse()
{
  std::string name;
  std::cout << "Please enter the name of your course: ";
  std::getline( std::cin, name );

  course = Course( name );
}

Assignment getAssignment( Course c )
{
  // TODO:
  return Assignment();
}

std::string getCategory( Course c )
{
  // TODO:
  return "";
}

void addAssign()
{
  std::string a_name;
  std::string a_cat;
  double      a_score     = 0.0;
  double      a_max_score = 0.0;

  // Get Name Score Max-Score, and Category
  std::cout << "Enter the assignment name: ";
  std::getline( std::cin, a_name );
  std::cout << "Enter the assignment score: ";
  std::cin >> a_score;
  std::cin.ignore();
  std::cout << "Enter the assignment max score: ";
  std::cin >> a_max_score;
  std::cin.ignore();
  std::cout << "Enter the assignment category: ";
  std::getline( std::cin, a_cat );

  course.addAssignment( Assignment( a_name, a_score, a_max_score, a_cat ) );
}

void removeAssignment()
{
  Assignment assign = getAssignment( course );
  course.removeAssignment( assign.name() );
}

void editAssignment()
{
  Assignment assign = getAssignment( course );

  while( true )
  {
    std::cout << "What would you like to edit? \n"
              << "1. Score     - " << assign.score() << "\n"
              << "2. Max Score - " << assign.maxScore() << "\n"
              << "3. Category  - " << assign.category() << "\n"
              << "Enter Choice: ";
    std::string input;
    std::getline( std::cin, input );

    if( input == "1" )
    {
      // Edit Score

      double a_score = 0.0;
      std::cout << "The current Score is " << assign.score() << ".\n"
                << "Enter the new Score: ";
      std::cin >> a_score;
      std::cin.ignore();

      assign.score( a_score );

      return;
    }
    if( input == "2" )
    {
      // Edit Max Score

      double a_maxScore = 0.0;
      std::cout << "The current max Score is " << assign.maxScore() << ".\n"
                << "Enter the new Max Score: ";
      std::cin >> a_maxScore;
      std::cin.ignore();

      assign.maxScore( a_maxScore );

      return;
    }
    if( input == "3" )
    {
      // Edit Category

      std::string a_cat;
      std::cout << "The current Category is " << assign.category() << ".\n"
                << "Enter the new Category: ";
      std::getline( std::cin, a_cat );

      assign.category( a_cat );

      return;
    }
    std::cout << "\n\nUnknown Input\n";
  }
}

void addCategory()
{
  std::string c_name;
  double      c_weight = 0.0;

  // Get Name and Weight
  std::cout << "Enter the category name: ";
  std::getline( std::cin, c_name );
  std::cout << "Enter the category weight: ";
  std::cin >> c_weight;
  std::cin.ignore();

  course.addCategory( c_name, c_weight );
}

void removeCategory()
{
  std::string category = getCategory( course );
  course.removeCategory( category );
}

void editCategory()
{
  double      c_weight = 0.0;
  std::string category = getCategory( course );

  std::cout << "The current weight is " << course.categories()[category] << ".\n"
            << "Enter the new Weight: ";
  std::cin >> c_weight;

  course.editCategory( category, c_weight );
}

int main()
{
  FMenu init_menu( "Get Course" );
  init_menu.addMenuOption( menuOption( "Load", "Load an existing course", loadCourse ) );
  init_menu.addMenuOption( menuOption( "New", "\tCreate a new course", newCourse ) );

  FMenu main_menu( "Course Menu" );
  main_menu.addMenuOption( menuOption( "Save Course", "Save the course to a file", save ) );
  main_menu.addMenuOption( menuOption( "Get Grade", "Print out the current grade for this course", save ) );

  FMenu assignment_menu( "Assignment Menu" );
  assignment_menu.addMenuOption( menuOption( "Add", "\tAdd a new Assignment", addAssign ) );
  assignment_menu.addMenuOption( menuOption( "Remove", "Remove an Assignment", removeAssignment ) );
  assignment_menu.addMenuOption( menuOption( "Edit", "Edit an Assignment", editAssignment ) );

  FMenu category_menu( "Category Menu" );
  category_menu.addMenuOption( menuOption( "Add", "\tAdd a new Category", addCategory ) );
  category_menu.addMenuOption( menuOption( "Remove", "Remove a Category", removeCategory ) );
  category_menu.addMenuOption( menuOption( "Edit", "Edit a Category", editCategory ) );

  main_menu.addSubMenu( assignment_menu );
  main_menu.addSubMenu( category_menu );

  init_menu.runMenu();
  main_menu.runMenuContinuous();
}