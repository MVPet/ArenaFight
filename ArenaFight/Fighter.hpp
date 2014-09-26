#ifndef _FIGHTER
#define _FIGHTER

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "AnimationHolder.hpp"

#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>

#include <string>

namespace sf
{
	class RenderWindow;
}

class Fighter
{
public:
	enum Type
	{ Kenshiro };

public:
					Fighter(Type type, sf::Vector2f position);

	void			update(sf::Time dt);
	void			load();
	void			draw(sf::RenderWindow& window) const;

	void				setVelocity(float x, float y);
	sf::Vector2f		getVelocity() const;

	void				setPosition(float x, float y);
	sf::Vector2f		getPosition() const;

	void				setGrounded(bool grounded);

	sf::FloatRect		getGroundBox() const;

	void				MoveLeft();
	void				MoveRight();
	void				Guard();

private:
	void		changeAnimation(Animation::Type type);
	std::string typeToString();

private:
	bool			mGrounded;
	Type			mType;
	Animation		mCurrentAnim;
	AnimationHolder mAnimations;
	TextureHolder	mTextures;
	sf::Vector2f	mPosition;
	sf::Vector2f	mVelocity;
	sf::FloatRect	mGroundBox;
};

#endif // Fighter.hpp