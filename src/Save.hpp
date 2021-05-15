#pragma once

#include <string>

#include "Course.hpp"

namespace saver
{
  void   saveCourse( Course c, std::string filename = "" );    // Save Course to a file
  Course loadCourse( std::string filename );                   // Load a Course from a file
}    // namespace saver