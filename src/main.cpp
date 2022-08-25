#include "ecs/ecs.h"
#include "components/character_components.h"
#include "defs.h"

#include <iostream>
#include <string>

int main(void)
{
    entt::registry registry{};

    const auto entity = registry.create();
    Registry reg();
    
    auto view = registry.view<Component>();

    view.each([](const auto&entity)
    {
        Print("iter");
    });

}