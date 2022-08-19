// The main example/test app for functional.hxx 
#include <iostream>
#include <vector>

#include "functional.hxx"

template<typename T>
void print_vec(std::vector<T>& vec) {
    std::cout << "{ ";
    each(vec, [](auto& x) { std::cout << x << " "; });
    std::cout << "}";
}

void optionals() {
    std::cout << "===========================" << std::endl;
    // This is privated and should not be possible. Construction is done through the static some and none methods.
    // std::cout << "Create an optional of int 5 through constructor..." << std::endl;
    // Option<int> oi(5);
    // std::cout << "Attempting to unwrap the Option<int>(5): " << *oi.unwrap() << std::endl;
    std::cout << "Attempting to create a simple int option through the static some method..." << std::endl;
    auto oi = Option<int>::some(5);
    std::cout << "Is the damn thing actually some? " << (oi.is_some() ? "yes" : "no") << std::endl;
    std::cout << "Attempting to unwrap the int option, should be 5: " << *oi.unwrap() << std::endl;

    std::cout << std::endl << "Attempting to create none from static function..." << std::endl;
    auto on = Option<int>::none();
    std::cout << "Is the damn thing actually none? " << (on.is_none() ? "yes" : "no") << std::endl;

    std::cout << std::endl << "Does the some() static method work? " << std::endl;
    std::cout << "Creating Option<std::string> with string equal to 'KEKW'..." << std::endl;
    auto os = Option<std::string>::some(std::string("KEKW"));
    std::cout << "Is the thing none? " << (os.is_none() ? "yes" : "no") << std::endl;
    std::cout << "Is the thing some? " << (os.is_some() ? "yes" : "no") << std::endl;
    std::cout << "Attempting to unwrap the string: " << *os.unwrap() << std::endl;

    std::cout << std::endl << "Does Option<T> work with a vector of ints?" << std::endl;
    auto ov = Option<std::vector<int>>::some({1, 2, 3});
    std::cout << "Vector is: ";
    print_vec(*ov.unwrap());

    // std::cout << std::endl << "Attempting to unwrap a none should result in a throw..." << std::endl;
    // auto oe = Option<int>::none();
    // oe.unwrap();
    std::cout << "===========================" << std::endl;
}


void transformations() {
    std::cout << "==========================" << std::endl;
    std::cout << "Creating a simple vector of {1, 2, 3}..." << std::endl;
    std::vector<uint32_t> v {1, 2, 3};
    std::cout << "Attempting to map it with + 1..." << std::endl;
    std::vector<uint32_t> vmapped { map(v, [](auto& x) { return x + 1; }) };
    std::cout << "The mapped vec is: ";
    print_vec(vmapped); std::cout << std::endl;

    std::cout << std::endl << "The vector is: {2, 4, 6, 8}." << std::endl;
    std::vector<uint8_t> vallany {2, 4, 6, 8};
    std::cout << "all(odd): " << (all(vallany, [](auto& x) { return x % 2 != 0; }) ? "yes" : "no") << std::endl;
    std::cout << "all(even): " << (all(vallany, [](auto& x) { return x % 2 == 0; }) ? "yes" : "no") << std::endl;
    std::cout << "any(= 2): " << (any(vallany, [](auto& x) { return x == 2; }) ? "yes" : "no") << std::endl;
    std::cout << "all(= 2): " << (all(vallany, [](auto& x) { return x == 2; }) ? "yes" : "no") << std::endl;

    std::cout << std::endl << "Try filtering all even elements from ";
    std::vector<uint16_t> vf {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_vec(vf); std::cout << std::endl;
    filter(vf, [](auto& x) { return x % 2 == 0; });
    print_vec(vf); std::cout << std::endl;
    std::cout << "Filter <= 6: ";
    filter(vf, [](auto& x) { return x <= 6; });
    print_vec(vf); std::cout << std::endl;
    std::cout << "=========================" << std::endl;
}

int main() {
    optionals();
    transformations();
    return 0;
}