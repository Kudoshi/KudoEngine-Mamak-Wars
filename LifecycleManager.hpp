#pragma once
#include "GameObject.hpp"

namespace KudoEngine
{
	class LifecycleManager
	{
		public:
			void StartLifeCycleManager();
		private:
			void Awake();
			void Start();
			void Update();
			void EnginePhysics();
			void Render();
			void Destroy();
			void OnApplicationQuit();
			
	};

}