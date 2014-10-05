/*
* AnimFrame.hpp
* Holds the data for a single frame of an animation
* Data stored is the hurtbox, hitbox, and how long the frame should last
*/

#ifndef _ANIMFRAME
#define _ANIMFRAME

#include <SFML/Graphics.hpp>

class AnimFrame
{
public:
			AnimFrame(sf::IntRect hurtBox, sf::IntRect attackBox, float frameTime);
			AnimFrame(sf::IntRect hurtBox, float frameTime);

	float	getFrameTime();

	sf::IntRect getAttackBox() const;
	sf::IntRect getBoundBox() const;

private:
	float		mFrameTime;
	bool		mHasAttackBox;

	sf::IntRect	 mHurtBox;
	sf::IntRect	 mAttackBox;
};

#endif // AnimFrame.hpp