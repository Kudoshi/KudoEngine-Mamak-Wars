#include "raylib.h"
#include "Engine.hpp"
#include <iostream>
using namespace KudoEngine;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
	std::cout << "[Main] Start Engine\n";

	Engine::Instance().StartEngine();
}