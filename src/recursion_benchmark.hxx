#ifndef RECBEN_HXX
#define RECBEN_HXX

#include <cstdint>

uint64_t recursive_sum(uint64_t progression_size, uint64_t acc) {
    if(progression_size == 0)
        return acc;

    return recursive_sum(progression_size - 1, acc + progression_size);
}

uint64_t recursive_noacc(uint64_t progression_size) {
    if(progression_size == 0)
        return 0;
    
    return progression_size + recursive_noacc(progression_size - 1);
}

uint64_t progression_sum(uint64_t progression_size) {
    uint64_t acc = 0;
    for(uint64_t i = 0; i <= progression_size; i++) {
        acc += i;
    }
    return acc;
}

#endif