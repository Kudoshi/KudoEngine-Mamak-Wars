#include "GameObjectManager.hpp"

namespace KudoEngine
{
	GameObject::GameObject()
	{ 
		_isActive = true;

	}

	void GameObject::Awake()
	{
	}

	void GameObject::Start()
	{
	}

	void GameObject::Update()
	{
	}

	void GameObject::Render()
	{
	}



	void GameObject::InternalAwake()
	{
		for (auto behaviour = _awakeComponents.begin(); behaviour != _awakeComponents.end(); )
		{
			(*behaviour)->Awake();

			_startComponents.push_back(*behaviour);
			behaviour = _awakeComponents.erase(behaviour);
		}
	}

	void GameObject::InternalStart()
	{
		if (!_isActive) return;

		for (auto behaviour = _startComponents.begin(); behaviour != _startComponents.end(); )
		{
			if (!(*behaviour)->IsEnabled())
			{
				++behaviour;
				continue;
			}

			(*behaviour)->Start();

			behaviour = _startComponents.erase(behaviour);
		}
	}

	void GameObject::InternalUpdate()
	{
		if (!_isActive) return;

		for (auto& behaviour : _components)
		{
			if (!behaviour.get()->IsEnabled()) continue;

			behaviour.get()->Update();
		}
	}

	void GameObject::InternalRender()
	{
		if (!_isActive) return;

		for (auto& behaviour : _components)
		{
			if (!behaviour.get()->IsEnabled()) continue;

			behaviour.get()->Render();
		}
	}
}