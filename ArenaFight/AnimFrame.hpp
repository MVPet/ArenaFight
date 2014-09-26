#ifndef _ANIMFRAME
#define _ANIMFRAME

#include <SFML/Graphics.hpp>

class AnimFrame
{
public:
			AnimFrame(sf::IntRect hurtBox, sf::IntRect attackBox, float frameTime);
			AnimFrame(sf::IntRect hurtBox, float frameTime);

	float	getFrameTime();

private:
	float		mFrameTime;
	bool		mHasAttackBox;

	sf::IntRect	 mHurtBox;
	sf::IntRect	 mAttackBox;
};

#endif // AnimFrame.hpp