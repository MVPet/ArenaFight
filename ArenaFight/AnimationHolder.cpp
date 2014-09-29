#include "AnimationHolder.hpp"

// creates an animation wtih the given parameters through a pointer and adds the pointer to the map w/ the given type
void AnimationHolder::add(sf::Texture* texture, Animation::Type type, std::vector<AnimFrame> frameData, bool loop)
{
	Animation* anim (new Animation(texture, type, frameData, loop));

	auto inserted = mAnimationMap.insert(std::make_pair(type, anim));
	assert(inserted.second);
}

// Find the animation in our map and make sure we actually have it, then return it
Animation& AnimationHolder::get(Animation::Type type) const
{
	auto found = mAnimationMap.find(type);
	assert(found != AnimationMap.end());

	return *found->second;
}