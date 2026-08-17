#pragma once

namespace KudoEngine
{
	class Behaviour
	{
	public:
		virtual void Awake() = 0;
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}