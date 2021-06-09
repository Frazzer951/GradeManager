#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Assignment.hpp"
#include "Course.hpp"
#include "Save.hpp"

#include "FMenu/FMenu.hpp"

// Global course variable that is used by the menu
Course course;

void loadCourse()
{
  // Load a course file with a specified filename
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
  // Save the current course to a file
  std::string filename;

  std::cout << "Enter the desired filename: ";
  std::getline( std::cin, filename );

  saver::saveCourse( course, filename );
}

void newCourse()
{
  // Create a new course
  std::string name;
  std::cout << "Please enter the name of your course: ";
  std::getline( std::cin, name );

  course = Course( name );
}

void printVecOption( std::vector<std::string> vec )
{
  // Take a vector and print out all the values in a numbered format
  std::cout << "Chose from one of the below options:\n";

  for( int i = 0; i < vec.size(); i++ )
  {
    std::cout << '\t' << i + 1 << ". \t" << vec[i] << '\n';
  }
}

int getChoice()
{
  // Get user input in the form of a number
  int index = -1;
  std::cout << "Enter Choice: ";
  std::cin >> index;
  std::cin.ignore();
  return index;
}

Assignment getAssignment( Course c )
{
  // Get a specific assignments from the user in the course
  std::vector<std::string> assignVec;

  for( auto & [name, assign] : c.assignments() )
  {
    assignVec.push_back( name );
  }

  printVecOption( assignVec );
  int index = getChoice() - 1;

  return c.assignments()[assignVec[index]];
}

std::string getCategory( Course c )
{
  // Get a specific category from the user in the course
  std::vector<std::string> catVec;

  for( auto & [name, assign] : c.categories() )
  {
    catVec.push_back( name );
  }

  printVecOption( catVec );
  int index = getChoice() - 1;

  return catVec[index];
}

void addAssign()
{
  // Create and add a new assignment
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
  // Remove a user specified assignment
  Assignment assign = getAssignment( course );
  course.removeAssignment( assign.name() );
}

void editAssignment()
{
  // Edit an existing assignment
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
  // Add a new category to the course
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
  // Remove a category from the course
  std::string category = getCategory( course );
  course.removeCategory( category );
}

void editCategory()
{
  // Edit and existing category
  double      c_weight = 0.0;
  std::string category = getCategory( course );

  std::cout << "The current weight is " << course.categories()[category] << ".\n"
            << "Enter the new Weight: ";
  std::cin >> c_weight;
  std::cin.ignore();

  course.editCategory( category, c_weight );
}

// Print the current grade of the course
void printGrade() { course.calcGrade(); }

int main()
{
  // Create menu that will get course object
  FMenu init_menu( "Get Course" );
  init_menu.addMenuOption( menuOption( "Load", "Load an existing course", loadCourse ) );
  init_menu.addMenuOption( menuOption( "New", "\tCreate a new course", newCourse ) );

  // Define the basic course menu
  FMenu main_menu( "Course Menu" );
  main_menu.addMenuOption( menuOption( "Save Course", "Save the course to a file", save ) );
  main_menu.addMenuOption( menuOption( "Get Grade", "Print out the current grade for this course", printGrade ) );

  // Define the assignment menu
  FMenu assignment_menu( "Assignment Menu" );
  assignment_menu.addMenuOption( menuOption( "Add", "\tAdd a new Assignment", addAssign ) );
  assignment_menu.addMenuOption( menuOption( "Remove", "Remove an Assignment", removeAssignment ) );
  assignment_menu.addMenuOption( menuOption( "Edit", "Edit an Assignment", editAssignment ) );

  // Define the category menu
  FMenu category_menu( "Category Menu" );
  category_menu.addMenuOption( menuOption( "Add", "\tAdd a new Category", addCategory ) );
  category_menu.addMenuOption( menuOption( "Remove", "Remove a Category", removeCategory ) );
  category_menu.addMenuOption( menuOption( "Edit", "Edit a Category", editCategory ) );

  // Add the submenus
  main_menu.addSubMenu( assignment_menu );
  main_menu.addSubMenu( category_menu );

  // Run the get course menu, then start the main menu
  init_menu.runMenu();
  main_menu.runMenuContinuous();
}