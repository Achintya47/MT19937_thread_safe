#ifndef MT19937
#define MT19937
#include <cstdint>

/**
 * @brief Masking Constants specific to temper function
 */
#define MT_D 0xFFFFFFFFU
#define MT_B 0x9d2c5680U
#define MT_C 0xEFC60000U


class mt19937{
    private:
        uint32_t _mt[624];
        uint16_t _index;

        // Implememted in mt19937_twist.cpp
        void twist();
        // Implemented in mt19937.cpp
        static uint32_t temper(uint32_t);
    public:
        explicit mt19937(uint32_t seed);
        uint32_t next();
};

#endif