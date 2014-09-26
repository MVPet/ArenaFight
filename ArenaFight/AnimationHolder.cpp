#include "AnimationHolder.hpp"

void AnimationHolder::add(sf::Texture* texture, Animation::Type type, std::vector<AnimFrame> frameData, bool loop)
{
	Animation* anim (new Animation(texture, type, frameData, loop));

	auto inserted = mAnimationMap.insert(std::make_pair(type, anim));
	assert(inserted.second);
}

Animation& AnimationHolder::get(Animation::Type type, bool reset) const
{
	auto found = mAnimationMap.find(type);
	assert(found != AnimationMap.end());

	//if(reset)
		//found->second->reset();

	return *found->second;
}