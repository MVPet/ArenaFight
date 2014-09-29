/*
* A sprite Animation
* Contains one sprite and the texture rectangle dictates what square of the sheet to display
* once the update time has been passed, move on to the next frame
*/

#ifndef _ANIMATION
#define _ANIMATION

#include "AnimFrame.hpp"

#include <string>

class Animation
{
public:
	enum Type
	{ 
		Stand, Run, Falling, Landing, 
		Guard, NLight, DLight, SLight, ULight
	};

public:
					Animation();
					Animation(sf::Texture* texture, Type type, std::vector<AnimFrame> frameData, bool loop);

	void			update(sf::Time dt, sf::Vector2f position, float xScale);
	void			draw(sf::RenderWindow& window) const;

	Type			getType() const;
	bool			getIsDone() const;
	sf::Vector2i	getFrameSize() const;

	void			setScale(float x, float y);

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