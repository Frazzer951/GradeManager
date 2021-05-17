#pragma once

#include <map>
#include <string>
#include <vector>

#include "Assignment.hpp"

class Course
{
public:
  friend bool operator==( const Course & _Left, const Course & _Right );

  // Type Definition Alias
  using CategoryWeights = std::map<std::string /*Category*/, double /*Weight*/>;
  using Assignments     = std::map<std::string /*Name    */, Assignment>;
  using Categories      = std::map<std::string /*Category*/, std::vector<Assignment>>;

  // Constructor
  Course( std::string name = "", std::map<std::string, double> categories = {} );

  // Queries
  std::string     name();           // Return the name of the course
  CategoryWeights categories();     // Returns map of categories and weights
  Assignments     assignments();    // Returns map of assignments

  // Mutator
  void addCategory( std::string catName, double weight );        // Add a Category
  void removeCategory( std::string catName );                    // Remove a Category
  void editCategory( std::string catName, double newWeight );    // Change a Category's weight
  void addAssignment( Assignment assign );                       // Add an assignment to the course
  void addAssignments( std::vector<Assignment> assigns );        // Add multiple assignments to the course
  void removeAssignment( std::string name );                     // Remove an assignment from the course

  // Operations
  void calcGrade();            // Print out the total grade
  void calcUncategorized();    // Calculate the Weight of Uncategorized

private:
  std::string     _name;
  CategoryWeights _categories;
  Assignments     _assignments;
};
