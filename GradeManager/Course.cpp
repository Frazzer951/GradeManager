#include <iostream>
#include <string>

#include "Course.h"

// Constructor
Course::Course( std::string name, std::map<std::string, double> categories ) : _name( name ), _categories( categories ) {}

// Queries
std::map<std::string, double>     Course::categories() { return _categories; }
std::map<std::string, Assignment> Course::assignments() { return _assignments; }

// Mutators
void Course::addCategory( std::string catName, double weight )
{
  if( _categories.find( catName ) == _categories.end() )
  {
    _categories[catName] = weight;
  }
  else
  {
    std::cout << "There is already a category with name " << catName << '\n';
  }
}

void Course::removeCategory( std::string catName )
{
  if( _categories.find( catName ) == _categories.end() )
  {
    std::cout << "There is no category with name " << catName << '\n';
  }
  else
  {
    _categories.erase( catName );
  }
}

void Course::editCategory( std::string catName, double newWeight )
{
  auto it = _categories.find( catName );
  if( it == _categories.end() )
  {
    std::cout << "There is no category with name " << catName << '\n';
  }
  else
  {
    it->second = newWeight;
  }
}

void Course::addAssignment( Assignment assign )
{
  if( _assignments.find( assign.name() ) == _assignments.end() )
  {
    _assignments[assign.name()] = assign;
  }
  else
  {
    std::cout << "An assignment with name " << assign.name() << " already exists! \n";
  }
}

void Course::removeAssignment( std::string name )
{
  if( _assignments.find( name ) == _assignments.end() )
  {
    std::cout << "An assignment with name " << name << " does not exists! \n";
  }
  else
  {
    _assignments.erase( name );
  }
}

void Course::calcGrade()
{
  /// Separate all assignments into categories
  /// For each category print out name and points off all assignment, overall category grade, and how much that category adds to final grade
  /// Sum up total grade and print it out to user

  Categories gradeCategories;
  double     overallPercent = 0;

  for( auto & [name, assignment] : _assignments )
  {
    if( _categories.find( assignment.category() ) != _categories.end() )
    {
      gradeCategories[assignment.category()].push_back( assignment );
    }
    else
    {
      gradeCategories["Uncategorized"].push_back( assignment );
      std::cout << assignment.name() << " was not in a known category and will be added to \"Uncategorized\" \n";
    }
  }

  for( auto & [category, assignments] : gradeCategories )
  {
    double weight      = _categories.find( category )->second;
    double totalPoints = 0;
    double maxPoints   = 0;

    std::cout << category << ": " << weight << "% of Overall Grade \n";
    for( auto & assignment : assignments )
    {
      totalPoints += assignment.score();
      maxPoints += assignment.maxScore();
      std::cout << '\t' << assignment << '\n';
    }
    double percent      = ( totalPoints / maxPoints ) * 100;
    double totalPercent = percent * ( weight / 100 );
    std::cout << std::string( 25, '-' ) << '\n'
              << "Total Score is" << totalPoints << '/' << maxPoints << " = " << percent << "%\n"
              << "Which is " << totalPercent << "% of the final grade \n\n\n";
    overallPercent += totalPercent;
  }

  std::cout << "The Final Grade is " << overallPercent << "% \n\n";
}
