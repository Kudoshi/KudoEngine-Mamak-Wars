#pragma once
#include "Engine.hpp"
using namespace KudoEngine;

namespace Game
{
	class TestObject : public Component
	{
	public:
		TestObject(GameObject& gameObject) : Component(gameObject) {}

		void Awake() override {
			Print("[Debug] AWAKE test object");

		}

		void Start() override
		{
			Print("[Debug] Start test object");
		}

		void Update() override
		{
			//Print("[Debug] update!");

		}

		void Render() override
		{
			//Print("[Debug] Rendering!");
		}
	};
}