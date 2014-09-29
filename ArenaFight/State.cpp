#include "State.hpp"
#include "StateStack.hpp"

// Set up the context of our state
State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts)
: window(&window)
, textures(&textures)
, fonts(&fonts)
{}

// Set up our state
State::State(StateStack& stack, Context context)
: mStack(&stack)
, mContext(context)
{}

// Deconstructor
State::~State()
{}

void State::requestStackPush(States::ID stateID)
{ mStack->pushState(stateID); }

void State::requestStackPop()
{ mStack->popState(); }

void State::requestStateClear()
{ mStack->clearStates(); }

State::Context State::getContext() const
{ return mContext; }
