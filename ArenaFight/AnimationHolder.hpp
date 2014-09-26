#ifndef _ANIMATIONHOLDER
#define _ANIMATIONHOLDER

#include "Animation.hpp"

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

class AnimationHolder
{
public:
	void		add(sf::Texture* texture, Animation::Type type, std::vector<AnimFrame> frameData, bool loop);
	Animation&	get(Animation::Type type, bool reset) const;

private:
	std::map<Animation::Type, Animation*> mAnimationMap;
};

#endif // AnimationHolder.hpp