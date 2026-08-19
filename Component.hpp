#pragma once

namespace KudoEngine
{
	class Component
	{
	public:
		virtual void Awake() {};
		virtual void Start() {};
		virtual void Update() {};
		virtual void Render() {};
		bool IsEnabled() const { return _isEnabled; };

	private:
		bool _isEnabled = true;
	};
}