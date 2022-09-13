#pragma once
#include "component.h"

class HealthComponent : public Component
{
public:
    HealthComponent() {}
    HealthComponent(uint16_t health)
        : m_Health(health)
    {}

    ~HealthComponent() override {}
    void SetHealth(uint16_t new_health) { m_Health = new_health; }
    const uint16_t &GetHealth() { return m_Health; }

private:
    uint16_t m_Health = 100;
};

class DamageComponent: public Component
{
public:
    DamageComponent(uint16_t damage)
    : m_Damage(damage)
    {}
    void SetDamage(uint16_t damage) { m_Damage = damage; }
    const uint16_t &GetDamage() { return m_Damage; }
private:
    uint16_t m_Damage = 20;
};

enum class DamageType
{
    PHYSICAL,
    FIRE,
    ICE,
};

struct DamageTypeComponent
{
    DamageType type;
};