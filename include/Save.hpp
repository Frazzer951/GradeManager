#ifndef SAVE_H
#define SAVE_H
#pragma once

#include <string>

#include "Course.hpp"

namespace saver
{
  void   saveCourse( Course c, std::string filename = "" );    // Save Course to a file
  Course loadCourse( const std::string & filename );           // Load a Course from a file
}    // namespace saver

#endif
