#pragma once
#include <memory>
#include <vector>
#include "Component.hpp"


namespace KudoEngine
{
	class GameObject
	{
	public:
		GameObject(); 


	public: 
		void InternalAwake();
		void InternalStart();
		void InternalUpdate();
		void InternalRender();
		bool IsActive() const { return _isActive; };
		std::vector<std::unique_ptr<Component>>& GetComponents() { return _components; }


		template<typename T>
		T& AddComponent() {
			static_assert(std::is_base_of_v<Component, T>);

			auto component = std::make_unique<T>();
			T& ref = *component;
			Component* rawComponent = component.get();

			_components.push_back(std::move(component));
			_awakeComponents.push_back(rawComponent);

			return ref;
		}

	
	protected:
		virtual void Awake();
		virtual void Start();
		virtual void Update();
		virtual void Render();

	private:
		std::vector<Component*> _awakeComponents;
		std::vector<Component*> _startComponents;
		std::vector<std::unique_ptr<Component>> _components;
		bool _isActive = true;

	};
}