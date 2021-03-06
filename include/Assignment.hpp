#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#pragma once

#include <string>
#include <string_view>

class Assignment
{
public:
  // Operators
  friend std::ostream & operator<<( std::ostream & stream, const Assignment & assignment );
  friend std::istream & operator>>( std::istream & stream, Assignment & assignment );
  friend bool           operator==( const Assignment & lhs, const Assignment & rhs );

  // Constructor
  Assignment( std::string_view name     = {},
              double           score    = 0.0,
              double           maxScore = 0.0,
              std::string_view category = {} );

  // Queries
  [[nodiscard]] std::string name() const;        // Get the name
  [[nodiscard]] std::string category() const;    // Get the category name
  [[nodiscard]] double      score() const;       // Get the score
  [[nodiscard]] double      maxScore() const;    // Get the max score

  // Mutators
  void name( std::string_view newName );            // Change the name
  void score( double newScore );                    // Change the score
  void maxScore( double newMaxScore );              // Change the max score
  void category( std::string_view newCategory );    // Change the category

private:
  std::string _name;
  double      _score;
  double      _maxScore;
  std::string _category;
};

#endif