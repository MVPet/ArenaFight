#include "Application.hpp"

#include <stdexcept>
#include <iostream>

// Try to run the game
// if we run into an error, spit it out
int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
