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
		GameObject(int objectID);


	public: 
		void InternalAwake();
		void InternalStart();
		void InternalUpdate();
		void InternalRender();
		void InternalDestroy();
		bool IsActive() const { return _isActive; };
		int GetObjectID() const { return _objectID; };
		void DestroySelf() { _setToDestroy = true; };


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

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args) {
			static_assert(std::is_base_of_v<Component, T>, "T must be derived from KudoEngine::Component");
			static_assert(std::is_constructible<T, GameObject&, Args...>::value, "T must be constructible from a GameObject& and the supplied arguments");

			auto component = std::make_unique<T>(*this, std::forward<Args>(args)...);
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
		virtual void Destroy();

	private:
		int _objectID;
		std::vector<Component*> _awakeComponents;
		std::vector<Component*> _startComponents;
		std::vector<std::unique_ptr<Component>> _components;
		bool _isActive = true;
		bool _setToDestroy = false;
	};
}