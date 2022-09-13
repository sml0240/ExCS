#pragma once
#include "../ecs/ecs.h"

class Scene
{
public:
    Scene(){}
    virtual ~Scene(){}
    entt::registry &GetRegistry() { return m_Registry; }
    Entity CreateEntity() { return Entity(m_Registry); }

private:
    entt::registry m_Registry;
};