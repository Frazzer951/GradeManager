#pragma once
#include <string>

class Assignment
{
public:
  std::string name();                         // Get the name
  void        name( std::string newName );    // Change the name

  double score();                     // Get the score
  void   score( double newScore );    // Change the score

  double maxScore();                        // Get the max score
  void   maxScore( double newMaxScore );    // Change the max score

  std::string category();                             // Get the category name
  void        category( std::string newCategory );    // Change the category

private:
  std::string _name;
  double      _score;
  double      _maxScore;
  std::string _category;

  Assignment( std::string name, double score, double maxScore, std::string category );
};
