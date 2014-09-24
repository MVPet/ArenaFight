#ifndef _STAGE
#define _STAGE

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Drawable.hpp>

class Stage
{
public:
	enum ID
	{ Training };

public:
			Stage();
	void	update();
	void	draw() const;

private:
	ID id;
};

#endif // Stage.hpp