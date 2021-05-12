#pragma once

#include <map>
#include <string>
#include <vector>

#include "Assignment.h"

class Course
{
public:
  // Type Definition Alias
  using CategoryWeights = std::map<std::string /*Category*/, double /*Weight*/>;
  using Assignments     = std::map<std::string /*Name    */, Assignment>;
  using Categories      = std::map<std::string /*Category*/, std::vector<Assignment>>;

  // Constructor
  Course( std::string name, std::map<std::string, double> categories = {} );

  // Queries
  std::map<std::string, double>     categories();     // Returns map of categories and weights
  std::map<std::string, Assignment> assignments();    // Returns map of assignments

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
