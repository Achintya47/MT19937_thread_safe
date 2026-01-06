#include "mt19937.hpp"
#include "mt19937_consts.hpp"

/**
 * @brief Performs the twist transformation for MT19937 
 * 
 * This function updates the internal state array _mt by
 * combining the upper bits of one word with lower bits of the
 * next word, then applying the twist transformation.
 */
void mt19937::twist(){
    uint32_t x;
    uint32_t xA;
    for (uint16_t i = 0; i < MT_N; i++){
        x = (_mt[i] & MT_UPPER_MASK) | (_mt[(i+1) % MT_N] & MT_LOWER_MASK);
        xA = x >> 1;
        if (x & 0x1)
            xA ^= MT_MATRIX_A;
        _mt[i] = _mt[(i + MT_M) % MT_N] ^ xA;
    }
}   