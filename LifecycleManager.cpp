#include "LifecycleManager.hpp"
#include "Engine.hpp"
#include "raylib.h"
#include "CollisionManager.hpp"

namespace KudoEngine
{
	void LifecycleManager::StartLifeCycleManager()
	{
        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            Awake();
            Start();

            Update();
            EnginePhysics();
            Render();
        }

        // De-Initialization
        //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

	}

    void LifecycleManager::Awake()
    {
        std::map<int, std::unique_ptr<GameObject>>* objects = G_GameObjectManager().GetGameObjects();
        
        if (objects->empty()) return;

        for (auto& obj : *objects)
        {
            obj.second.get()->InternalAwake();
        }
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

    void LifecycleManager::Update()
    {
        std::map<int, std::unique_ptr<GameObject>>* objects = Engine::Instance().GetGameObjectManager().GetGameObjects();

        if (objects->empty()) return;

        for (auto& obj : *objects)
        {
            obj.second.get()->InternalUpdate();
        }
    }

    void LifecycleManager::EnginePhysics()
    {
        CollisionManager::Instance().InternalPhysicsLoop();
    }
    
    void LifecycleManager::Render()
    {
        BeginDrawing();
        ClearBackground(BLACK);

        std::map<int, std::unique_ptr<GameObject>>* objects = Engine::Instance().GetGameObjectManager().GetGameObjects();

        if (objects->empty()) return;

        for (auto& obj : *objects)
        {
            obj.second.get()->InternalRender();
        }
     

        EndDrawing();
    }

    void LifecycleManager::Destroy()
    {
        std::map<int, std::unique_ptr<GameObject>>* objects = Engine::Instance().GetGameObjectManager().GetGameObjects();

        if (objects->empty()) return;

        for (auto& obj : *objects)
        {
            obj.second.get()->InternalDestroy();
        }


    }
}