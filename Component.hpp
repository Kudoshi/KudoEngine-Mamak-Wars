#pragma once

namespace KudoEngine
{
	class GameObject;
	class Transform;

	class Component
	{
	public:
		Component(GameObject& gameObject) : _gameObject(gameObject), _transform(nullptr) {} // Only for transform to use

		void InternalAwake() { Awake(); };
		void InternalStart() { Start(); };
		void InternalUpdate() { Update(); };
		void InternalRender() { Render(); };
		void InternalDestroy() { Destroy(); };


		GameObject& GetGameObject() { return _gameObject; };
		Transform& GetTransform() { return *_transform; };
		bool IsEnabled() const { return _isEnabled; };
		void InternalSetTransform(Transform& transform) { _transform = &transform; };

	private:
		bool _isEnabled = true;
		GameObject& _gameObject;
		Transform* _transform = nullptr;

	protected:
		virtual void Awake() {};
		virtual void Start() {};
		virtual void Update() {};
		virtual void Render() {};
		virtual void Destroy() {};
	};
}