#ifndef _ANIMATION
#define _ANIMATION

#include "AnimFrame.hpp"

#include <string>

class Animation
{
public:
	enum Type
	{ Stand, Run, Guard, NLight, DLight, SLight, ULight, AnimationCount };

public:
					Animation();
					Animation(sf::Texture* texture, Type type, std::vector<AnimFrame> frameData, bool loop);

	void			update(sf::Time dt, sf::Vector2f position);
	void			draw(sf::RenderWindow& window) const;
	void			reset();

	Type			getType() const;
	bool			getIsDone() const;
	sf::Vector2i	getFrameSize() const;

	void			setScale(float x, float y);

private:
	void			load(std::string charName);
	std::string		typeToString();

private:
	Type					mType;
	sf::Texture*			mTexture;
	sf::Sprite				mSprite;
	std::vector<AnimFrame>	mFrameData;

	int						mFrameIndex;
	int						mNumOfFrames;
	float					mUpdateTime;
	bool					mLoop;
	bool					mIsDone;
	int						mFrameWidth;
	int						mFrameHeight;
};

#endif // Animation.hpp