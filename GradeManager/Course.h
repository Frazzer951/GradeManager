#pragma once
#include <map>
#include <string>

#include "Assignment.h"

class Course
{
public:
  std::map<std::string, double> categories();                                             // Returns map of categories and weights
  void                          addCategory( std::string catName, double weight );        // Add a Category
  void                          removeCategory( std::string );                            // Remove a Category
  void                          editCategory( std::string catName, double newWeight );    // Change a Category's weight

  void addAssignment( Assignment assign );      // Add an assignment to the course
  void removeAssignment( std::string name );    // Remove an assignment from the course

  void calcGrade();    // Print out the total grade

private:
  std::string                       _name;
  std::map<std::string, double>     _categories;
  std::map<std::string, Assignment> _assignments;

  Course( std::string name, std::map<std::string, double> categories );
};
