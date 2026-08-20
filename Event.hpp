#pragma once

#include <vector>
#include <functional>
#include <cstddef>

namespace KudoEngine
{
    template<typename... Args>
    class Event
    {
    public:
        using Callback = std::function<void(Args...)>;

        size_t Subscribe(Callback callback)
        {
            size_t id = _nextId++;

            _listeners.push_back({id, std::move(callback)});

            return id;
        }

        void Unsubscribe(size_t id)
        {
            for (auto it = _listeners.begin(); it != _listeners.end(); ++it)
            {
                if (it->id == id)
                {
                    _listeners.erase(it);
                    return;
                }
            }
        }

        void Invoke(Args... args)
        {
            for (auto& listener : _listeners)
            {
                listener.callback(args...);
            }
        }

    private:
        struct Listener
        {
            size_t id;
            Callback callback;
        };

        std::vector<Listener> _listeners;

        size_t _nextId = 0;
    };
}