// A small functional library written as an attempt to have fun with C++.
#ifndef FUNCTIONAL_HXX
#define FUNCTIONAL_HXX

#include <memory>
#include <exception>
#include <algorithm>

// ===== TYPES ======
template<typename T>
class Option {
    private:
        std::unique_ptr<T> value;
        Option(T&& newval): value(std::make_unique<T>(newval)) {}
        Option(): value(nullptr) {}
    public:
        bool is_some() {
            return value != nullptr;
        }
        bool is_none() {
            return value == nullptr;
        }
        T* unwrap() {
            if(value)
                return value.release();
            else
                throw std::domain_error("Attempted to unwrap a none Option.");
        }

        static Option<T> some(T&& newval) {
            return Option<T>(std::move(newval));
        }
        static Option<T> none() {
            return Option<T>();
        }
};

// ====== ALGORITHMS ========
template<typename T, typename F>
std::vector<T>& map(std::vector<T>& vec, F f) {
    std::transform(vec.begin(), vec.end(), vec.begin(), f);
    return vec;
}

template<typename T, typename F>
std::vector<T>& each(std::vector<T>& vec, F f) {
    std::for_each(vec.begin(), vec.end(), f);
    return vec;
}

template<typename T, typename F>
bool all(std::vector<T>& vec, F f) {
    return std::all_of(vec.begin(), vec.end(), f);
}

template<typename T, typename F>
bool any(std::vector<T>& vec, F f) {
    return std::any_of(vec.begin(), vec.end(), f);
}

template<typename T, typename F>
std::vector<T>& filter(std::vector<T>& vec, F f) {
    std::erase_if(vec, [=](auto& x) { return f(x) == false; });
    return vec;
}

#endif // FUNCTIONAL_HXX