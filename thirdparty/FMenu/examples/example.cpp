#include <iostream>

#include "FMenu/FMenu.hpp"

void op1()
{
  std::cout << "You chose option 1!\n";
}

void op2()
{
  std::cout << "You chose option 2!\n";
}

void sop1()
{
  std::cout << "You chose sub-option 1!\n";
}

void sop2()
{
  std::cout << "You chose sub-option 2!\n";
}

int main()
{
  FMenu menu( "Main Menu" );
  menu.addMenuOption( menuOption( "Option 1", "This is an example option", op1 ) );
  menu.addMenuOption( menuOption( "Option 2", "This is an example option", op2 ) );

  FMenu subMenu( "Sub Menu" );
  subMenu.addMenuOption( menuOption( "Do Something", "This is an example sub-option", sop1 ) );
  subMenu.addMenuOption( menuOption( "Do Something Else", "This is an another example sub-option", sop2 ) );
  menu.addSubMenu( subMenu );

  menu.runMenuContinuous();
}