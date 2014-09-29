/*
* Fighter.hpp
* The Character the player controls
* All the logic for the fighter is done in here, such as how far to move, determining what state he/she/it should be in, etc.
* Extremely unfinished, also needs to fix flipping the direction of the character, simply setting the scale isn't going to cut it
*/

#ifndef _FIGHTER
#define _FIGHTER

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "AnimationHolder.hpp"

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Transformable.hpp>

#include <string>

namespace sf
{
	class RenderWindow;
}

class Fighter : public sf::Transformable
{
public:
	enum Type
	{ 
		Kenshiro, 
		CharacterCount 
	};

	enum State
	{ 
		None, Guarding, Hit, Attacking, Lag,
		StateCount 
	};

public:
					Fighter(Type type, sf::Vector2f position);

	void			update(sf::Time dt);
	void			load();
	void			draw(sf::RenderWindow& window) const;

	void				setVelocity(float x, float y);
	sf::Vector2f		getVelocity() const;

	void				setGrounded(bool grounded);

	void				setState(State state);
	State				getState() const;

	sf::FloatRect		getGroundBox() const;

	void				MoveLeft();
	void				MoveRight();
	void				Guard();

	void				NeutralLightAttack();
	void				SideLightAttack(float xScale);
	void				UpLightAttack();
	void				DownLightAttack();

private:
	void		changeAnimation(Animation::Type type);
	std::string typeToString();

private:
	bool			mGrounded;
	float			mFlip;

	Type			mType;
	State			mState;
	Animation		mCurrentAnim;
	AnimationHolder mAnimations;
	TextureHolder	mTextures;
	sf::Vector2f	mVelocity;
	sf::FloatRect	mGroundBox;
};

#endif // Fighter.hpp