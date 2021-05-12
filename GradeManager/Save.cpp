#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Course.h"
#include "Save.h"

std::string spaceToUnderscore( std::string str )
{
  for( int i = 0; i < str.length(); i++ )
  {
    if( str[i] == ' ' )
      str[i] = '_';
  }
  return str;
}

void saver::saveCourse( Course c, std::string filename )
{
  if( filename == "" ) filename = spaceToUnderscore( c.name() ) + ".course";
  std::ofstream courseFile;
  courseFile.open( filename );

  // Course Name
  courseFile << c.name() << '\n';

  // Course Weights
  for( auto & [category, weight] : c.categories() )
  {
    if( category == "Uncategorized" ) continue;
    courseFile << std::quoted( category ) << '\t' << weight << '\n';
  }
  courseFile << "END_CATEGORIES\n";

  // Assignments
  for( auto & [name, assignment] : c.assignments() )
  {
    courseFile << std::quoted( assignment.name() ) << ", "
               << assignment.score() << '/'
               << assignment.maxScore() << ", "
               << std::quoted( assignment.category() ) << '\n';
  }

  courseFile.close();
}

Course saver::loadCourse( std::string filename )
{
  std::ifstream fin( filename );

  std::string course_name;
  std::getline( fin, course_name );    // Get course name

  Course loadedCourse( course_name );

  std::string catName;
  double      weight;

  while( true )
  {
    fin >> std::quoted( catName );
    if( catName == "END_CATEGORIES" ) break;
    fin >> weight;
    loadedCourse.addCategory( catName, weight );
  }

  Assignment temp;
  while( fin >> temp )
  {
    loadedCourse.addAssignment( temp );
  }

  return loadedCourse;
}