#include "GameObjectManager.hpp"

namespace KudoEngine
{
	void GameObject::InternalStart()
	{
		if (_startInitialized) return;

		_startInitialized = true;
		Start();
	}

	void GameObject::Start()
	{
		for (auto& behaviour : _components)
		{
			behaviour.get()->Start();
		}
	}
}