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
		None, Guarding, Hurt, Attacking, Lag,
		StateCount 
	};

public:
						Fighter(Type type, sf::Vector2f position);

	void				update(sf::Time dt);
	void				load();
	void				draw(sf::RenderWindow& window) const;

	void				setVelocity(float x, float y);
	sf::Vector2f		getVelocity() const;

	void				setGrounded(bool grounded);

	void				setState(State state);
	State				getState() const;

	sf::FloatRect		getGroundBox() const;

	sf::IntRect			getAttackBox() const;
	sf::IntRect			getBoundBox() const;

	int					getDamage() const;
	int					getNumOfHits() const;
	float				getHitStun() const;
	sf::Vector2f		getKnockBack() const;

	void				addHit();
	int					getTotalHits() const;


	void				changeAnimation(Animation::Type type);

	void				takeDamage(int amount, float hitStun, float xKnockBack, float yKnockBack);

	void				MoveLeft();
	void				MoveRight();
	void				Jump();
	void				Guard();

	void				NeutralLightAttack();
	void				SideLightAttack(float xScale);
	void				UpLightAttack();
	void				DownLightAttack();

private:
	void			directionUpdate();
	std::string		typeToString();
	Animation::Type	getLeftAnimEnum(Animation::Type type);
	Animation::Type getRightAnimEnum(Animation::Type type);

private:
	int				mHealth;
	int				mWeight;
	int				mTotalHits;

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