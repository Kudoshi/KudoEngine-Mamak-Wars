#pragma once
#include <memory>
#include <vector>
#include "Behaviour.hpp"


namespace KudoEngine
{
	class GameObject
	{
	public: 
		void InternalStart();

		template<typename T>
		T& AddComponent() {
			static_assert(std::is_base_of_v<Behaviour, T>);

			auto component = std::make_unique<T>();
			T& ref = *component;

			_components.push_back(std::move(component));

			return ref;
		}

	
	protected:
		virtual void Start();

	private:
		bool _startInitialized = false;
		std::vector<std::unique_ptr<Behaviour>> _components;

	};
}