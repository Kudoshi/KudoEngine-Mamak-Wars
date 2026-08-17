#include "LifecycleManager.hpp"
#include "Engine.hpp"
#include "raylib.h"

namespace KudoEngine
{
	void LifecycleManager::StartLifeCycleManager()
	{
        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            Start();
            // Call Start


            OnRender();
        }

        // De-Initialization
        //--------------------------------------------------------------------------------------
        //CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

	}

    void LifecycleManager::Start()
    {
        std::map<int, std::unique_ptr<GameObject>>* objects = Engine::Instance().GetGameObjectManager().GetGameObjects();

        if (objects->empty()) return;

        for (auto& obj : *objects)
        {
            obj.second.get()->InternalStart();
        }
    }

    void LifecycleManager::OnRender()
    {
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
}