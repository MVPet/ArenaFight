#ifndef _FIGHTER
#define _FIGHTER

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>

class Fighter : public sf::Transformable
{
public:
	enum ID
	{ Kenshiro };

public:
			Fighter();
	void	update();
	void	draw() const;

private:
	ID	id;
};

#endif // Fighter.hpp