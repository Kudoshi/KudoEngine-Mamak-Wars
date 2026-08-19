#include "GameObjectManager.hpp"
#include "Transform.hpp"

namespace KudoEngine
{
	GameObject::GameObject()
	{ 
		_isActive = true;
		AddComponent<Transform>();
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
			(*behaviour)->InternalAwake();

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

			(*behaviour)->InternalStart();

			behaviour = _startComponents.erase(behaviour);
		}
	}

	void GameObject::InternalUpdate()
	{
		if (!_isActive) return;

		for (auto& behaviour : _components)
		{
			if (!behaviour.get()->IsEnabled()) continue;

			behaviour.get()->InternalUpdate();
		}
	}

	void GameObject::InternalRender()
	{
		if (!_isActive) return;

		for (auto& behaviour : _components)
		{
			if (!behaviour.get()->IsEnabled()) continue;

			behaviour.get()->InternalRender();
		}
	}
}