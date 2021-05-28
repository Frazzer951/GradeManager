#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Course.hpp"
#include "Save.hpp"
#include "json.hpp"

using json = nlohmann::json;

std::string spaceToUnderscore( const std::string & str )
{
  std::string tmp_str;
  for( char c : str )
  {
    if( c == ' ' )
      tmp_str += '_';
    else
      tmp_str += c;
  }
  return tmp_str;
}

void saver::saveCourse( Course c, std::string filename )
{
  if( filename.empty() ) filename = spaceToUnderscore( c.name() ) + ".json";
  else
    filename += ".json";
  std::ofstream courseFile;
  courseFile.open( filename );

  json json_course;

  // Name
  json_course["name"] = c.name();

  // Categories
  int i = 0;
  for( auto & [name, weight] : c.categories() )
  {
    if( name == "Uncategorized" ) continue;
    json_course["categories"][i]["name"]   = name;
    json_course["categories"][i]["weight"] = weight;
    i++;
  }

  // Assignments
  i = 0;
  for( auto & [name, assignment] : c.assignments() )
  {
    json_course["assignments"][i]["name"]      = assignment.name();
    json_course["assignments"][i]["score"]     = assignment.score();
    json_course["assignments"][i]["max_score"] = assignment.maxScore();
    json_course["assignments"][i]["category"]  = assignment.category();
    i++;
  }

  courseFile << std::setw( 4 ) << json_course;
  courseFile.close();
}

Course saver::loadCourse( const std::string & filename )
{
  std::ifstream fin( filename );

  json json_course;
  fin >> json_course;

  // Create course with course name
  Course loaded_course( json_course["name"] );

  // Load Categories
  for( auto category : json_course["categories"] )
  {
    loaded_course.addCategory( (std::string) category["name"], (double) category["weight"] );
  }

  // Load Assignments
  for( auto assignment : json_course["assignments"] )
  {
    loaded_course.addAssignment( Assignment( (std::string) assignment["name"], (double) assignment["score"], (double) assignment["max_score"], (std::string) assignment["category"] ) );
  }

  return loaded_course;
}