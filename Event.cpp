#include "Event.hpp"
#include <functional>

namespace KudoEngine
{
	size_t Event::Subscribe(Callback callback)
	{
		_nextID++;
		size_t id = _nextId;

		_listeners.push_back({ id, std::move(callback) });

		return id;
	}
}