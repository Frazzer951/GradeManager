#include "menu.hpp"

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
      std::string filename;
      std::getline( std::cin, filename );

      if( !std::filesystem::exists( filename ) )
      {
        std::cout << "File not found! Try again\n";
        continue;
      }

      return saver::loadCourse( filename );

      break;
    }
    if( input == "New" || input == "new" )
    {
      // Start a new course

      std::cout << "Please enter the name of your course: ";
      std::getline( std::cin, input );

      return Course( input );

      break;
    }

    std::cout << "Unknown Input!\n";
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

Assignment get_Assignment_From_Vec( std::vector<Assignment> assignments )
{
  std::cout << "Select Assignment from one of the following: ";
  for( int i = 0; i < assignments.size(); i++ )
  {
    std::cout << i + 1 << ". " << assignments[i].name() << '\n';
  }
  std::cout << "Enter Choice: ";
  int choice = 0;
  std::cin >> choice;

  return assignments[choice - 1];
}

std::string get_Category_From_Vec( std::vector<std::string> categories )
{
  std::cout << "Select Category from one of the following: ";
  for( int i = 0; i < categories.size(); i++ )
  {
    std::cout << i + 1 << ". " << categories[i] << '\n';
  }
  std::cout << "Enter Choice: ";
  int choice = 0;
  std::cin >> choice;

  return categories[choice - 1];
}

std::vector<Assignment> AssignmentMapToVector( const std::map<std::string, Assignment> & assignments, const std::string & category )
{
  std::vector<Assignment> assigns;

  for( const auto & [name, assignment] : assignments )
  {
    if( category.empty() )
      assigns.push_back( assignment );
    else
    {
      if( assignment.category() == category ) assigns.push_back( assignment );
    }
  }

  return assigns;
}

std::vector<std::string> CategoryMapToVector( const std::map<std::string, double> & categories )
{
  std::vector<std::string> cats( categories.size() );

  int i = 0;
  for( const auto & [name, weight] : categories )
  {
    cats[i] = name;
    i++;
  }

  return cats;
}

Assignment get_Assignments( Course & course )
{
  while( true )
  {
    std::cout << "Do you want to see all courses or just one category?\n"
              << "1. All Courses\n"
              << "2. One Category\n"
              << "Enter Choice: ";
    std::string input;
    std::getline( std::cin, input );

    if( input == "1" )
    {
      auto assign_vec = AssignmentMapToVector( course.assignments() );
      return get_Assignment_From_Vec( assign_vec );
    }
    if( input == "2" )
    {
      auto category_vec = CategoryMapToVector( course.categories() );
      auto category     = get_Category_From_Vec( category_vec );
      auto assign_vec   = AssignmentMapToVector( course.assignments(), category );
      return get_Assignment_From_Vec( assign_vec );
    }

    std::cout << "\n\nUnknown Input!\n";
  }
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
      std::string a_name;
      std::string a_cat;
      double      a_score     = 0.0;
      double      a_max_score = 0.0;

      // Get Name Score Max-Score, and Category
      std::cout << "Enter the assignment name: ";
      std::getline( std::cin, a_name );
      std::cout << "Enter the assignment score: ";
      std::cin >> a_score;
      std::cout << "Enter the assignment max score: ";
      std::cin >> a_max_score;
      std::cout << "Enter the assignment category: ";
      std::getline( std::cin, a_cat );

      course.addAssignment( Assignment( a_name, a_score, a_max_score, a_cat ) );
      return;
    }
    if( input == "2" )
    {
      // Remove Assignment
      Assignment assign = get_Assignments( course );
      course.removeAssignment( assign.name() );
      return;
    }
    if( input == "3" )
    {
      // TODO: Impliment editing
      std::cout << "This Function hasn't been implemented yet!";
      return;

      // Edit Assignment
      Assignment assign = get_Assignments( course );
    }
    if( input == "4" || input == "q" || input == "quit" || input == "Quit" )
    {
      return;
    }

    std::cout << "Unknown Input!\n";
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
    if( input == "1" || input == "2" || input == "3" )
    {
      // TODO: Impliment editing
      std::cout << "This Function hasn't been implemented yet!";
      return;

      // Add Section
    } /*
    if( input == "2" )
    {
      // TODO: Impliment editing
      std::cout << "This Function hasn't been implemented yet!";
      return;

      // Remove Section
    }
    if( input == "3" )
    {
      // TODO: Impliment editing
      std::cout << "This Function hasn't been implemented yet!";
      return;

      // Edit Section
    }*/
    if( input == "4" || input == "q" || input == "quit" || input == "Quit" )
    {
      return;
    }

    std::cout << "Unknown Input!\n";
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