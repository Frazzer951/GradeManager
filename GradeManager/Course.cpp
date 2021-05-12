#include <iostream>
#include <string>

#include "Course.h"

// Constructor
Course::Course( std::string name, std::map<std::string, double> categories ) : _name( name ), _categories( categories ) { calcUncategorized(); }

// Queries
std::string             Course::name() { return _name; }
Course::CategoryWeights Course::categories() { return _categories; }
Course::Assignments     Course::assignments() { return _assignments; }

// Mutators
void Course::addCategory( std::string catName, double weight )
{
  if( weight < 0 )
  {
    std::cout << "Weights must be positive!";
    return;
  }

  if( _categories.find( catName ) == _categories.end() )
  {
    _categories[catName] = weight;
  }
  else
  {
    std::cout << "There is already a category with name " << catName << '\n';
  }
  calcUncategorized();
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
  calcUncategorized();
}

void Course::editCategory( std::string catName, double newWeight )
{
  if( newWeight < 0 )
  {
    std::cout << "Weights must be positive!";
    return;
  }

  auto it = _categories.find( catName );
  if( it == _categories.end() )
  {
    std::cout << "There is no category with name " << catName << '\n';
  }
  else
  {
    it->second = newWeight;
  }
  calcUncategorized();
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

void Course::addAssignments( std::vector<Assignment> assigns )
{
  for( auto & assign : assigns )
  {
    addAssignment( assign );
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

// Operations
void Course::calcGrade()
{
  /// Separate all assignments into categories
  /// For each category print out name and points off all assignment, overall category grade, and how much that category adds to final grade
  /// Sum up total grade and print it out to user

  if( _assignments.empty() ) { return; }

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
      std::cout << assignment.name() << " was not in a known category and will be added to \"Uncategorized\" \n\n\n";
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
    std::cout << '\t' << std::string( 25, '-' ) << '\n'
              << "\tTotal Score is " << totalPoints << '/' << maxPoints << " = " << percent << "%\n"
              << "\tWhich is " << totalPercent << "% of the final grade \n\n\n";
    overallPercent += totalPercent;
  }

  std::cout << "The Final Grade is " << overallPercent << "% \n\n";
}

void Course::calcUncategorized()
{
  if( _categories.empty() )
  {
    _categories["Uncategorized"] = 100;
    return;
  }

  double totalWeights = 0;
  for( auto & [category, weight] : _categories )
  {
    if( category == "Uncategorized" ) continue;
    totalWeights += weight;
  }
  double uncatWeight = 100 - totalWeights;
  if( uncatWeight >= 0 && uncatWeight <= 100 )
  {
    _categories["Uncategorized"] = uncatWeight;
  }
  else
  {
    _categories["Uncategorized"] = 0;
    std::cout << "Category Weights add up to more than 100!\n";
  }
}