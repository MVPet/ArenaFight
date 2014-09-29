/*
* ResourceIdentifiers.hpp
* All of the potential resources we could pull and what there ID would be
*/

#ifndef _RESOURCEIDENTIFIERS
#define _RESOURCEIDENTIFIERS

namespace sf
{
	class Texture;
	class Font;
}

namespace Textures
{
	enum ID
	{ 
		TitleScreen, Background, Platform, Ground, 
		Stand, Run, Falling, Landing, 
		Guard, NLight, SLight, ULight, DLight 
	};
}

namespace Fonts
{
	enum ID
	{ Menu };
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>			FontHolder;

#endif // ResourceIdentifiers.hpp