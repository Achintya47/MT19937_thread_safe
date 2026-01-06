#include <iostream>
#include <cstdint>
#include "mt19937.hpp"
#include "mt19937_consts.hpp"

/**
 * @brief Constructor for the mt19937 algorithm
 * @note This is the LCD implementation (Linear Congruential Generator)
 * 
 * Sets the _index value to 624 for initial twist() call
 * @param seed for populating the MT Matrix
 */
mt19937::mt19937(const uint32_t seed){
    _index = 624;
    uint32_t _gseed = seed;
    for (int i = 0; i < 51; i++){
        _gseed = _gseed * 69069 + 1;
    }
    for (int i = 0; i < 624; i++){
        _gseed = 69069 * _gseed + 1;
        _mt[i] = _gseed & 0xFFFFFFFF;
    }
}

/**
 * @brief Temper function for standard MT19937
 * 
 * Called only by mt19937::next(), Stateless and independent
 * of mt19937::twist()
 */
uint32_t mt19937::temper(uint32_t value){
    uint32_t y = value;
    y ^= (y >> 11);
    y ^= (y << 7) & MT_B;
    y ^= (y << 15) & MT_C;
    y ^= y >> 18;
    return y;
}

uint32_t mt19937::next(){
    if (_index >= MT_N){
        twist();
        _index = 0;
    }
    uint32_t output = temper(_mt[_index]);
    _index++;
    return output;    
}