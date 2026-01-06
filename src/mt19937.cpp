#include <iostream>

class mt19937{
    private:
        uint32_t _mt[624];
        uint16_t _index;
        void twist();
        static uint32_t temper(uint32_t);
    public:
        mt19937(const uint32_t);
        uint32_t next();
};

/*
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