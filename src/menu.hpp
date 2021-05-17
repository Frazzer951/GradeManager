#ifndef MENU_H
#define MENU_H
#pragma once

#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Assignment.hpp"
#include "Course.hpp"
#include "Save.hpp"

Course get_Course();

Assignment get_Assignment_From_Vec( const std::vector<Assignment> & assignments );
Assignment get_Assignments( const Course & course );

std::vector<Assignment>  AssignmentMapToVector( std::map<std::string, Assignment> & assignments, std::string category = "" );
std::vector<std::string> CategoryMapToVector( std::map<std::string, double> & categories );

std::string get_Category_From_Vec( std::vector<std::string> & categories );
std::string get_main_menu();
std::string get_assignment_menu();
std::string get_section_menu();

void assignment_menu( Course & course );
void section_menu( Course & course );
void user_input_handler( Course & course );

#endif