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
			//void LateUpdate();
			//void OnPreRender();
			void Render();
			//void OnPostRender();
			void OnApplicationQuit();
			
	};

}