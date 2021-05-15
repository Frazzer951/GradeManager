#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

#include "Assignment.hpp"

// Constructor
Assignment::Assignment( std::string_view name, double score, double maxScore, std::string_view category ) : _name( name ), _score( score ), _maxScore( maxScore ), _category( category ) {}

// Queries
std::string Assignment::name() const { return _name; }
double      Assignment::score() const { return _score; }
double      Assignment::maxScore() const { return _maxScore; }
std::string Assignment::category() const { return _category; }

// Mutators
void Assignment::name( std::string_view newName ) { _name = newName; }
void Assignment::score( double newScore ) { _score = newScore; }
void Assignment::maxScore( double newMaxScore ) { _maxScore = newMaxScore; }
void Assignment::category( std::string_view newCategory ) { _category = newCategory; }

// Operators
std::ostream & operator<<( std::ostream & stream, const Assignment & assignment )
{
  const std::string delimiter  = ", ";
  const std::string delimiter2 = "/";

  stream << assignment.name() << delimiter
         << assignment.score() << delimiter2
         << assignment.maxScore();

  return stream;
}
std::istream & operator>>( std::istream & stream, Assignment & assignment )
{
  Assignment temp;
  char       delimiter  = ',';
  char       delimiter2 = '/';

  stream >> std::quoted( temp._name ) >> delimiter
      >> temp._score >> delimiter2
      >> temp._maxScore >> delimiter
      >> std::quoted( temp._category );

  if( stream ) assignment = std::move( temp );
  return stream;
}