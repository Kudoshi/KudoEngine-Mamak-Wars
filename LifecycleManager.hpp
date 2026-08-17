#pragma once
#include "GameObject.hpp"

namespace KudoEngine
{
	class LifecycleManager
	{
		public:
			void StartLifeCycleManager();
		private:
			void Start();
			void Update();
			void FixedUpdate();
			void LateUpdate();
			void OnPreRender();
			void OnRender();
			void OnPostRender();
			void OnApplicationQuit();
			
	};

}