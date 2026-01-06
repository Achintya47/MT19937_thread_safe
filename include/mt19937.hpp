/**
 * @file mt19937.hpp
 * @brief Declaration of mt19937 class.
 * @author Achintya
 * @date 2026-01-07
 */

#ifndef MT19937
#define MT19937
#include <cstdint>

/**
 * @class mt19937
 * @brief Mersenne Twister 19937 pseudo-random number generator (PRNG).
 *
 * This class implements the MT19937 algorithm, a widely used PRNG
 * with a period of 2^19937 - 1. It provides deterministic random
 * number generation based on a given seed.
 *
 * The implementation separates the twist and tempering operations
 * into different compilation units for modularity.
 */
class mt19937{
    private:
        /**
         * @brief Internal state array.
         *
         * The generator maintains 624 unsigned 32-bit integers
         * as its internal state.
         */
        uint32_t _mt[624];

        /**
         * @brief Current index into the state array.
         *
         * Indicates the position of the next value to be extracted.
         */
        uint16_t _index;

        /**
         * @brief Performs the twist transformation.
         *
         * Recomputes the internal state array when all values
         * have been consumed. Implemented in mt19937_twist.cpp.
         */
        void twist();
        
        /**
         * @brief Applies tempering to improve statistical properties.
         *
         * @param value Raw 32-bit integer from the state array.
         * @return Tempered 32-bit integer with improved distribution.
         *
         * Implemented in mt19937.cpp.
         */
        static uint32_t temper(uint32_t);

    public:
        /**
         * @brief Constructs the generator with a given seed.
         *
         * @param seed Initial seed value used to populate the state array.
         */
        explicit mt19937(uint32_t seed);

        /**
         * @brief Generates the next pseudo-random number.
         *
         * @return A 32-bit unsigned integer from the sequence.
         */
        uint32_t next();
};

#endif