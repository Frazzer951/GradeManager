#pragma once
#include <string>

class Assignment
{
public:
  // Operators
  friend std::ostream & operator<<( std::ostream & stream, const Assignment & assignment );

  // Constructor
  Assignment( std::string name, double score, double maxScore, std::string category );

  // Queries
  std::string name() const;        // Get the name
  std::string category() const;    // Get the category name
  double      score() const;       // Get the score
  double      maxScore() const;    // Get the max score

  // Mutators
  void name( std::string newName );            // Change the name
  void score( double newScore );               // Change the score
  void maxScore( double newMaxScore );         // Change the max score
  void category( std::string newCategory );    // Change the category

private:
  std::string _name;
  double      _score;
  double      _maxScore;
  std::string _category;
};
