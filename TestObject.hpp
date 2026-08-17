#pragma once
#include "Engine.hpp"
using namespace KudoEngine;

namespace Game
{
	class TestObject : public Behaviour
	{
		void Awake() override {

		}

		void Start() override
		{
			std::cout << "[Debug] Hello World\n";
		}

		void Update() override
		{

		}
	};
}