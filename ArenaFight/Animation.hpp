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
		Stand, LStand, Run, LRun, Falling, LFalling, Landing, LLanding, Hurt, LHurt,
		Guard, LGuard, NLight, LNLight, DLight, LDLight, SLight, LSLight, ULight, LULight
	};

public:
					Animation();
					Animation(sf::Texture* texture, Type type, std::vector<AnimFrame> frameData, bool loop);

	void			update(sf::Time dt, sf::Vector2f position);
	void			draw(sf::RenderWindow& window) const;

	Type			getType() const;
	bool			getIsDone() const;
	sf::Vector2i	getFrameSize() const;

	void			setFrameDuration(int frameIndex, float duration);

	void			setScale(float x, float y);

	sf::IntRect		getAttackBox() const;
	sf::IntRect		getBoundBox() const;

	int				getDamage() const;
	int				getNumOfHits() const;
	float			getHitStun() const;

	sf::Vector2f	getKnockBack() const;


private:
	Type					mType;
	sf::Texture*			mTexture;
	sf::Sprite				mSprite;
	std::vector<AnimFrame>	mFrameData;

	int						mFramesBetweenHit;
	int						mFrameIndex;
	int						mNumOfFrames;
	float					mUpdateTime;
	bool					mLoop;
	bool					mIsDone;
	int						mFrameWidth;
	int						mFrameHeight;
};

#endif // Animation.hpp