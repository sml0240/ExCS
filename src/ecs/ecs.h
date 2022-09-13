#pragma once
#include "../entt/entt.hpp"
#include "refs.h"
#include "pure_ecs.h"

#define EntityID entt::entity
#define EntityHandle entt::handle
#define ComponentList entt::registry
#define View entt::basic_view

class Entity
{
public:
    Entity(entt::registry &reg)
    {
        m_Handle = EntityHandle { reg, reg.create() };
    }
    ~Entity() {}

    EntityID GetEntityID() { return m_Handle.entity(); }

    template<typename T, typename ... Args>
    void AddComponent(Args&& ... args)
    {
        m_Handle.emplace<T>(std::forward<Args>(args)...);
    }

    template<typename ... Component>
    auto Get()
    {
        return m_Handle.get<Component...>();
    }

    template<typename ... Args>
    bool Has()
    {
        return m_Handle.any_of<Args...>();
    }

    template<typename ... Args>
    bool HasAll()
    {
        return m_Handle.all_of<Args...>();
    }
    void AddConstructSystem(void* system)
    {
        m_Systems.push_back(system);
    }
    void AddDestructSystem(void* system)
    {
        m_Registry.on_construct<
    }

private:
    EntityHandle m_Handle;
};

// class View
// {
// public:
//     template<typename A, typename B, typename C>
//     View(entt::basic_view<A, B, C> view) { m_View = view; }

// private:
//     Ref<entt::basic_view> m_View;    
// }

// class Registry
// {
// public:
//     Registry() {}
//     ~Registry() {}

//     Ref<Entity> CreateEntity() { return CreateRef<Entity>(m_Registry->create()); }
//     template <typename T>
//     void AddComponentAmount(Ref<Entity> &entity, Ref<T> &component, uint32_t amount);
//     template<typename T>
//     void AddComponent(Ref<Entity> &entity, T &component) { m_Registry->emplace<T>(entity, component); } 
//     template<typename C>
//     entt::basic_view<C, void, void> &GetView() { return m_Registry->view<C>(); }
//     template<typename C, typename O>
//     entt::basic_view<C, O, void> &GetView() { return m_Registry->view<C, O>(); }
//     template<typename C, typename O, typename E>
//     entt::basic_view<C, O, E> &GetView() { return m_Registry->view<C, O, E>(); }


// private:
//     Ref<entt::registry> m_Registry;
// };