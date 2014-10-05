#include "AnimFrame.hpp"

// Create the data on a frame that has both a hit and hurt box
AnimFrame::AnimFrame(sf::IntRect hurtBox, sf::IntRect attackBox, float frameTime)
	: mHurtBox(hurtBox)
	, mHasAttackBox(true)
	, mAttackBox(attackBox)
	, mFrameTime(frameTime)
{}

// Create the data on a frame that has only a hurt box
AnimFrame::AnimFrame(sf::IntRect hurtBox, float frameTime)
	: mHurtBox(hurtBox)
	, mHasAttackBox(true)
	, mAttackBox(sf::IntRect(5000, 5000, 5000, 5000))
	, mFrameTime(frameTime)
{}

float AnimFrame::getFrameTime()
{ return mFrameTime; }

sf::IntRect AnimFrame::getAttackBox() const
{ return mAttackBox; }

sf::IntRect AnimFrame::getBoundBox() const
{ return mHurtBox; }