#pragma once
#include <memory>
#include <type_traits>
#include <vector>
#include "Component.hpp"
#include "Transform.hpp"


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
		Transform& GetTransform() { return *static_cast<Transform*>(_components[0].get()); };
		std::vector<std::unique_ptr<Component>>& GetComponents() { return _components; }

		template<typename T>
		T* GetComponent()
		{
			static_assert(std::is_base_of_v<Component, T>);

			for (auto& component : _components)
			{
				if (T* casted = dynamic_cast<T*>(component.get()))
				{
					return casted;
				}
			}

			return nullptr;
		}

		template<typename T>
		T& AddComponent() {
			static_assert(std::is_base_of_v<Component, T>);
			static_assert(std::is_constructible_v<T, GameObject&>);

			auto component = std::make_unique<T>(*this);
			T& ref = *component;
			Component* rawComponent = component.get();

			_components.push_back(std::move(component));

			if (_components.size() > 1)
			{
				rawComponent->InternalSetTransform(GetTransform());
			}

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