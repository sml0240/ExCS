#pragma once

template <typename T>
using Unique = std::unique_ptr<T>;

template <typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

// template<typename F, typename S>
// using Pair = std::pair<F, S>;

// template<typename T>
// using Vector = std::vector<T>;

// print
#define Print(x) std::cout << (x) << std::endl;