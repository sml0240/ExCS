#pragma once

class Component
{
public:
    Component() {}
    Component(uint32_t id) : m_ID(id) {}
    virtual ~Component() {}
    const uint32_t &GetID() { return m_ID; }
    virtual void Update() {}

private:
    uint32_t m_ID;
};
