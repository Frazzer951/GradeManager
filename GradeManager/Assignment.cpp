#include <string>

#include "Assignment.h"



// Constructor
Assignment::Assignment( std::string name, double score, double maxScore, std::string category ) : _name( name ), _score( score ), _maxScore( maxScore ), _category( category ) {}

// Queries
std::string Assignment::name() const { return _name; }
double      Assignment::score() const { return _score; }
double      Assignment::maxScore() const { return _maxScore; }
std::string Assignment::category() const { return _category; }

// Mutators
void Assignment::name( std::string newName ) { _name = newName; }
void Assignment::score( double newScore ) { _score = newScore; }
void Assignment::maxScore( double newMaxScore ) { _maxScore = newMaxScore; }
void Assignment::category( std::string newCategory ) { _category = newCategory; }

// Operators
std::ostream & operator<<( std::ostream & stream, const Assignment & assignment )
{
  const std::string delim  = ": ";
  const std::string delim2 = "/";
  stream << assignment.name() << delim << std::to_string(assignment.score()) << delim2 << std::to_string(assignment.maxScore());

  return stream;
}
