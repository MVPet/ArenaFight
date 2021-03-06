/*
* Utility.hpp
* Contains an assortment of functions and classes that might be used anywhere in the program
*/

#ifndef _UTILITY
#define _UTILITY

#include <sstream>


namespace sf
{
	class Sprite;
	class Text;
}


template <typename T>
std::string toString(const T& value);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

#include "Utility.inl"

#endif // Utility.hpp