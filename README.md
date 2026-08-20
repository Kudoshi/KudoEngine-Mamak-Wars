KudoEngine : Mamak Wars
This focuses more on the game engine rather than the game
Mamak wars is a game about two Mamak guys fighting using Malaysian food. It is a top-down 2D quick arena brawl round style. Where each round is a quick 5 to 10seconds where you are required to shoot the other person using the food you have with each food having its own abilities. Every food is a one-shot on the enemy if it hits.

Mamak wars is built on top of KudoEngine which is built on top of Raylib. For this project, I wanted to prioritize building a component based engine similar to UnityEngine.

It has the following features:
-	Component based 
    -	Every game object has components
    -	Allows adding and removing components to gameobject
-	Lifecycle
    -	Every game object and component has its own lifecycle
-	The lifecycles are:
    -	Awake
    -	Start
    -	Update
    -	Render
-	Modular components
    - Components are to be reusable such as:
        - SpriteRenderer
        - Transform
        - Collider
-	Has event callbacks

Developers will then be able to use the Engine stuff and create their own components to make the game work
