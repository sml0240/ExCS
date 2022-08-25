#pragma once

#include "../entt/entt.hpp"

class Entity
{
public:
    Entity() {}
    ~Entity() {}
    template<typename T>
    void AddComponent(T component);

private:
    entt::entity m_EntityRef;
};

class Registry
{
public:
    Registry() {}
    ~Registry() {}
    entt::entity CreateEntity() { return m_Registry.create(); }
    template <typename T>
    void AddComponentAmount(entt::entity & entity, T &component, uint32_t amount);

private:
    entt::registry m_Registry;
};