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
					AnimFrame(sf::IntRect hurtBox, sf::IntRect attackBox, float frameTime, int damage, int hitStun, int numOfHits, float xKnockback, float yKnockback);
					AnimFrame(sf::IntRect hurtBox, float frameTime);

	float			getFrameTime();

	sf::IntRect		getAttackBox() const;
	void			setAttackBoxPosition(int top, int left);
	sf::IntRect		getBoundBox() const;
	void			setBoundBoxPosition(int top, int left);

	void			setFrameTime(float duration);

	int				getDamage() const;
	int				getNumOfHits() const;
	float			getHitStun() const;
	sf::Vector2f	getKnockBack() const;

private:
	float			mFrameTime;
	bool			mHasAttackBox;

	int				mDamage;
	int				mNumOfHits;
	float			mHitStun;
	sf::Vector2f	mKnockback;

	sf::IntRect		mHurtBox;
	sf::Vector2f	mHurtBoxPosition;
	sf::IntRect		mAttackBox;
	sf::Vector2f	mAttackBoxPosition;
};

#endif // AnimFrame.hpp