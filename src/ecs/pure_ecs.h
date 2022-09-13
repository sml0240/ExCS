#pragma once
#include "../entt/entt.hpp"
//template<typename Type, typename Other, typename ... Exclude>

//#define Delegate entt::delegate
#define delegate entt::delegate

template<typename R, typename C>
class Delegate
{
public:
    Delegate()
    {}

private:
    delegate<R(C)> m_Delegate;
};

template<typename R, typename C>
struct System
{
    uint32_t id;
    Delegate system;
};

class SystemPool
{
    
};

class Query
{
public:
    Query(){}
    Query(entt::entity &entity)
    {}
    ~Query(){}

private:

};

class EcsScene
{
public:
    EcsScene() {}
    ~EcsScene() {}

    entt::entity CreateEntity()
    {
        return m_Registry.create();
    }

    template<typename T, typename ... Args>
    void AddComponent(Args&& ... args)
    {
        m_Registry.emplace<T>(std::forward<Args>(args)...);
    }

    template<typename ... Component>
    auto Get(const entt::entity &entity)
    {
        return m_Registry.get<Component...>(entity);
    }

    template<typename ... Args>
    bool Has(const entt::entity &entity)
    {
        return m_Registry.any_of<Args...>(entity);
    }

    template<typename ... Args>
    bool HasAll(const entt::entity &entity)
    {
        return m_Registry.all_of<Args...>(entity);
    }

    void AddRuntimeSystem(void* system)
    {
        m_Systems.push_back(system);
    }
    void AddConstructSystem(void* system)
    {
        m_Registry.on_construct<
    }
    void AddDestructSystem(System system)
    {
        m_Registry.on_destruct<
    }
    
    void Update()
    {

    }

private:
    entt::registry m_Registry;
    std::vector<entt::delegate> m_Systems;
};