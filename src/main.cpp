#include "ecs/ecs.h"
#include "components/character_components.h"
#include "scene/scene.h"
//#include "refs.h"

#include <iostream>
#include <string>
#include <typeindex>
#include <typeinfo>


struct Dummy
{
    int x, y;
};
struct Dummy2
{
    int x, y;
};
struct Dummy3
{
    int x, y;
};


// Pure ecs main
int main(void)
{
    EcsScene scene;

    entt::entity ent = scene.CreateEntity();

    scene.AddComponent<Dummy3>(ent);

    entt::registry reg{};
    auto res = reg.view<
}

//int main(void)
//{
//    entt::registry registry{};
//    // scene and entities test
//    Scene* scene = new Scene();
//    Entity ent = scene->CreateEntity();
//    ent.AddComponent<Dummy2>(5, 5);
//    // Entity only test
//    Ref<Entity> myent = CreateRef<Entity>(registry);
//    myent->AddComponent<Dummy>(10, 10);
//    myent->AddComponent<Dummy2>(10, 10);
//
//    std::cout << "has component: " << myent->Has<Dummy>() << std::endl;
//    std::cout << "has all components: " << myent->HasAll<Dummy, Dummy2, Dummy3>() << std::endl;
//    std::cout << "has atleast 1 of the components: " << myent->Has<Dummy, Dummy3>() << std::endl;
//
//    auto my_comp_get = myent->Get<Dummy>();
//    std:: cout << "Got dummy\tx=" << my_comp_get.x << "\ty=" << my_comp_get.y << std::endl;
//    my_comp_get.x = 11;
//    auto my_comp_get2 = myent->Get<Dummy>();
//
//    std:: cout << "Got dummy2\tx=" << my_comp_get2.x << "\ty=" << my_comp_get2.y << std::endl;
//    std::cout << "Sizeof Entity: " << sizeof(myent) << std::endl;
//    std::cout << "Sizeof Dummy: " << sizeof(Dummy) << std::endl;
//}