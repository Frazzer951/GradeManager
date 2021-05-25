#ifndef COURSE_H
#define COURSE_H
#pragma once

#include <map>
#include <string>
#include <vector>

#include "Assignment.hpp"

class Course
{
public:
  friend bool operator==( const Course & lhs, const Course & rhs );

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
  void addCategory( const std::string & catName, const double & weight );    // Add a Category
  void removeCategory( const std::string & catName );                        // Remove a Category
  void editCategory( const std::string & catName, double newWeight );        // Change a Category's weight
  void addAssignment( const Assignment & assign );                           // Add an assignment to the course
  void addAssignments( const std::vector<Assignment> & assigns );            // Add multiple assignments to the course
  void removeAssignment( const std::string & name );                         // Remove an assignment from the course

  // Operations
  void calcGrade();            // Print out the total grade
  void calcUncategorized();    // Calculate the Weight of Uncategorized

private:
  std::string     _name;
  CategoryWeights _categories;
  Assignments     _assignments;
};

#endif