#ifndef MENU_H
#define MENU_H
#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class menuOption
{
  using functiontype = void ( * )();

  std::string  _name;
  std::string  _description;
  functiontype _f;

public:
  menuOption( std::string name = "", std::string desc = "", functiontype f = functiontype() ) : _name( std::move( name ) ), _description( std::move( desc ) ), _f( f ) {}

  std::string  name() { return _name; }                  // Get Name
  std::string  description() { return _description; }    // Get Description
  functiontype function() { return _f; }                 // Get Function

  void runFunction()
  {
    _f();
  }
};

class FMenu
{
  using menuOptions = std::map<std::string /*Option Name*/, menuOption /*Menu Option*/>;
  using subMenus    = std::map<std::string /*SubMenu Name*/, FMenu /*SubMenu*/>;

  // Variables
  std::string _name;
  char        _quit_key;
  char        _return_key;
  menuOptions _options;
  subMenus    _subMenus;

  // Private Functions
  void printMenu( std::vector<std::string> indexVector );      // Will print out the menu
  bool handleInput( std::vector<std::string> indexVector );    // Will take and parse user input

public:
  // Constructor
  FMenu( std::string name = "", char quit_key = 'q', char return_key = 'c' );

  // Queries
  std::string name();

  // Mutators
  void addSubMenu( FMenu subMenu );           // Add SubMenu
  void addMenuOption( menuOption option );    // Add Option to the menu

  // Functions
  void runMenu();              // Starts the Menu
  void runMenuContinuous();    // Run the Menu in a infinite while loop
};

#endif