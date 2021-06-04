#include "FMenu/FMenu.hpp"

bool isNum( const std::string & str )
{
  return std::all_of( str.begin(), str.end(), []( char c )
                      { return isdigit( c ); } );
}

// Constructor
FMenu::FMenu( std::string name, char quit_key, char return_key ) :
  _name( std::move( name ) ), _quit_key( quit_key ), _return_key( return_key ) {}

// Queries
std::string FMenu::name() { return _name; }

// Mutators
void FMenu::addSubMenu( FMenu subMenu ) { _subMenus[subMenu.name()] = subMenu; }
void FMenu::addMenuOption( menuOption option ) { _options[option.name()] = option; }

// Functions
void FMenu::runMenu()
{
  // Get all the Options and SubMenus into an indexable format
  std::vector<std::string> indexVector;
  for( auto & [name, option] : _options )
  {
    indexVector.push_back( name );
  }
  for( auto & [name, subMenu] : _subMenus )
  {
    indexVector.push_back( name );
  }

  while( true )
  {
    printMenu( indexVector );
    if( handleInput( indexVector ) ) break;
  }
}

void FMenu::runMenuContinuous()
{
  while( true ) runMenu();
}

void FMenu::printMenu( std::vector<std::string> indexVector )
{
  std::cout << "\n"
            << _name << '\n';

  for( int i = 0; i < indexVector.size(); i++ )
  {
    if( i < _options.size() )
    {
      std::cout << '\t' << i + 1 << ". " << _options[indexVector[i]].name() << ":\t" << _options[indexVector[i]].description() << "\n";
    }
    else
    {
      std::cout << '\t' << i + 1 << ". " << _subMenus[indexVector[i]].name() << "\n";
    }
  }
  std::cout << "\t" << _return_key << ". to Return" << '\n';
  std::cout << "\t" << _quit_key << ". to Exit" << '\n';
}

bool FMenu::handleInput( std::vector<std::string> indexVector )
{
  std::cout << "Enter Choice: ";
  std::string input;
  std::getline( std::cin, input );

  if( input[0] == _quit_key ) exit( 0 );
  if( input[0] == _return_key ) return true;
  if( !isNum( input ) )
  {
    std::cout << "Unknown Input";
    return false;
  }
  int index = std::stoi( input );
  if( index > _options.size() + _subMenus.size() || index <= 0 )
  {
    std::cout << "Entered Number out of range\n";
    return false;
  }

  if( index <= _options.size() )
  {
    _options[indexVector[index - 1]].runFunction();
    return true;
  }
  _subMenus[indexVector[index - 1]].runMenu();
  return true;
}