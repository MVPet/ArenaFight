#include "StateStack.hpp"

#include <cassert>

// Set up our stack
StateStack::StateStack(State::Context context)
: mStack()
, mPendingList()
, mContext(context)
, mFactories()
{}

// Updtaes our stack top to bottom
void StateStack::update(sf::Time dt)
{
	// Stop as soon as update() returns false
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->update(dt))
			break;
	}

	applyPendingChanges();
}

// Draw all active states from bottom to top
void StateStack::draw()
{
	for(State::Ptr& state : mStack)
		state->draw();
}

// Handle events thrown at the stack from top to bottom
void StateStack::handleEvent(const sf::Event& event)
{
	// Stop as soon as handleEvent() returns false
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
			break;
	}

	applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{ mPendingList.push_back(PendingChange(Push, stateID)); }

void StateStack::popState()
{ mPendingList.push_back(PendingChange(Pop)); }

void StateStack::clearStates()
{ mPendingList.push_back(PendingChange(Clear)); }

bool StateStack::isEmpty() const
{ return mStack.empty(); }

// Create a state by calling the constructor that we assigned in our map
State::Ptr StateStack::createState(States::ID stateID)
{
	auto found = mFactories.find(stateID);
	assert(found != mFactories.end());

	return found->second();
}

// Apply any pending changes we ahve to the stack
void StateStack::applyPendingChanges()
{
	for(PendingChange change: mPendingList)
	{
		switch (change.action)
		{
			case Push:
				mStack.push_back(createState(change.stateID));
				break;

			case Pop:
				mStack.pop_back();
				break;

			case Clear:
				mStack.clear();
				break;
		}
	}

	mPendingList.clear();
}

// Creates a change to the stack that needs to be applied
StateStack::PendingChange::PendingChange(Action action, States::ID stateID)
: action(action)
, stateID(stateID)
{}
