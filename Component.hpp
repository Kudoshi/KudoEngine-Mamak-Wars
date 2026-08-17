#pragma once

namespace KudoEngine
{
	class Component
	{
	public:
		virtual void Awake() = 0;
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		bool IsEnabled() const { return _isEnabled; };

	private:
		bool _isEnabled = true;
	};
}