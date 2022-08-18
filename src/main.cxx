// The main example/test app for functional.hxx 
#include <iostream>
#include <vector>

#include "functional.hxx"

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
    std::cout << "Vector's [2] element should be 3: " << (*ov.unwrap())[2] << std::endl;

    // std::cout << std::endl << "Attempting to unwrap a none should result in a throw..." << std::endl;
    // auto oe = Option<int>::none();
    // oe.unwrap();
    std::cout << "===========================" << std::endl;
}

int main() {
    optionals();
    return 0;
}