#include <iostream>
#include <cstdint>
#include "mt19937.hpp"


class mt19937{
    private:
        uint32_t _mt[624];
        uint16_t _index;
        void twist();
        static uint32_t temper(uint32_t);
    public:
        explicit mt19937(const uint32_t);
        uint32_t next();
};

/**
* @brief Constructor for growing and sowing seeds
* @param seed Seed value used to populate the matrix
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
uint32_t mt19937::temper(uint32_t _mt0){
    uint32_t y = _mt0;
    y ^= (y >> 11) & MT_D;
    y ^= (y << 5) & MT_B;
    y ^= (y << 15) & MT_C;
    y ^= y >> 18;
    return y;
}