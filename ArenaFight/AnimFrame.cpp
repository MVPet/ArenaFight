#include "AnimFrame.hpp"

// Create the data on a frame that has both a hit and hurt box
AnimFrame::AnimFrame(sf::IntRect hurtBox, sf::IntRect attackBox, float frameTime, int damage, int hitStun, int numOfHits, float xKnockback, float yKnockback)
	: mHasAttackBox(true)
	, mAttackBox(attackBox)
	, mAttackBoxPosition(attackBox.left, attackBox.top)
	, mHurtBox(hurtBox)
	, mHurtBoxPosition(hurtBox.left, hurtBox.top)
	, mFrameTime(frameTime)
	, mDamage(damage)
	, mHitStun(hitStun)
	, mNumOfHits(numOfHits)
	, mKnockback(xKnockback, yKnockback)
{}

// Create the data on a frame that has only a hurt box
AnimFrame::AnimFrame(sf::IntRect hurtBox, float frameTime)
	: mHasAttackBox(true)
	, mAttackBox(sf::IntRect(5000, 5000, 0, 0))
	, mAttackBoxPosition(5000, 5000)
	, mHurtBox(hurtBox)
	, mHurtBoxPosition(hurtBox.left, hurtBox.top)
	, mFrameTime(frameTime)
	, mDamage(0)
	, mHitStun(0)
	, mNumOfHits(0)
	, mKnockback(0, 0)
{}

float AnimFrame::getFrameTime()
{ return mFrameTime; }

sf::IntRect AnimFrame::getAttackBox() const
{ return mAttackBox; }

void AnimFrame::setAttackBoxPosition(int top, int left)
{
	mAttackBox.top =  mAttackBoxPosition.y + top;
	mAttackBox.left = mAttackBoxPosition.x + left;
}

void AnimFrame::setBoundBoxPosition(int top, int left)
{
	mHurtBox.left = mHurtBoxPosition.x + left;
	mHurtBox.top = mHurtBoxPosition.y + top;
}

sf::IntRect AnimFrame::getBoundBox() const
{ return mHurtBox; }

void AnimFrame::setFrameTime(float duration)
{ mFrameTime = duration; }

int AnimFrame::getDamage() const
{ return mDamage; }

int AnimFrame::getNumOfHits() const
{ return mNumOfHits; }

float AnimFrame::getHitStun() const
{ return mHitStun; }

sf::Vector2f AnimFrame::getKnockBack() const
{ return mKnockback; }