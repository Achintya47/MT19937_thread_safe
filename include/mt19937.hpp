#ifndef MT19937
#define MT19937
#include <cstdint>

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