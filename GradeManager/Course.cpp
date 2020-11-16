#include "Course.h"
#include <string>

Course::Course( std::string name, std::map<std::string, double> categories )
{
}

std::map<std::string, double> Course::categories()
{
  return std::map<std::string, double>();
}

void Course::addCategory( std::string catName, double weight )
{
}

void Course::removeCategory( std::string )
{
}

void Course::editCategory( std::string catName, double newWeight )
{
}

void Course::addAssignment( Assignment assign )
{
}

void Course::removeAssignment( std::string name )
{
}

void Course::calcGrade()
{
}
