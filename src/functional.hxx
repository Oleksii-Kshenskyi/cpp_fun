// A small functional library written as an attempt to have fun with C++.
#ifndef FUNCTIONAL_HXX
#define FUNCTIONAL_HXX

#include <memory>
#include <exception>


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

#endif // FUNCTIONAL_HXX