#pragma once

#include <signal.h>
#include <memory>
#include <iostream>
#include <vector>

/* DEFINE UTILS */

/* -------- print -------- */
//#define PRINT(x) std::cout << (x) << std::endl;

// /* -------- assert (linux raise signal) -------- */
// #define ASSERT(x) \
//     if (!(x))   \
//         raise(SIGTRAP);

/* -------- assert log -------- */
// #define ASSERT(x)   \
//     if(!(x))    \
//         AssertFailedLog(#x, __FILE__, __LINE__);

// inline void AssertFailedLog(const char *value, const char *file, int line)
// {
//     std::cout << "[Assert Failed] value: " << value << ", file: " << file << ", line: " << line << std::endl;
// }

/* -------- Smart Pointers -------- */

// template <typename T>
// using Unique = std::unique_ptr<T>;

// template <typename T>
// using Ref = std::shared_ptr<T>;

// template<typename T, typename ... Args>
// constexpr Ref<T> CreateRef(Args&& ... args)
// {
//     return std::make_shared<T>(std::forward<Args>(args)...);
// }

// template<typename F, typename S>
// using Pair = std::pair<F, S>;

// template<typename T>
// using Vector = std::vector<T>;

/* -------------------------------- */

/* -------- MATH -------- */
struct Vector2
{
    Vector2()
        : x(0.0f), y(0.0f)
    {}
    Vector2(float _x, float _y)
        : x(_x), y(_y)
    {}
    float x, y;
};

struct Vector2i
{
    Vector2i()
        : x(0), y(0)
    {}
    Vector2i(int _x, int _y)
        : x(_x), y(_y)
    {}
    int x, y;
};

struct Vector3
{
    Vector3()
        : x(0.0f), y(0.0f)
    {}
    Vector3(float _x, float _y, float _z)
        : x(_x), y(_y), z(_z)
    {}

    float x, y, z;
};
struct Vector3i
{
    Vector3i()
        : x(0), y(0)
    {}
    Vector3i(int _x, int _y, int _z)
        : x(_x), y(_y), z(_z)
    {}

    int x, y, z;
};

struct Vector4
{
    Vector4()
        : x(0.0f), y(0.0f)
    {}
    Vector4(float _x, float _y, float _z, float _a)
        : x(_x), y(_y), z(_z), a(_a)
    {}
    float x, y, z, a;
};
// LERP
static float Lerp(float from, float to, float t)
{
    return (from + (to - from)) * t;
}

static Vector2 Vector2Lerp(Vector2 from, Vector2 to, float t)
{
    Vector2 ret;
    ret.x = (from.x + (to.x - from.x)) * t; 
    ret.y = (from.y + (to.y - from.y)) * t; 
    return ret;
}

static Vector3 Vector3Lerp(Vector3 from, Vector3 to, float t)
{
    Vector3 ret;
    ret.x = (from.x + (to.x - from.x)) * t; 
    ret.y = (from.y + (to.y - from.y)) * t; 
    ret.z = (from.z + (to.z - from.z)) * t; 
    return ret;
}