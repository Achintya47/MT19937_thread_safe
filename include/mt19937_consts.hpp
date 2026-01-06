/**
 * @file mt19937_consts.hpp
 * @brief Declaration of Algorithm constants for the MT19937 Algorithm.
 * @author Achintya
 * @date 2026-01-07
 */

#ifndef MT19937_Consts
#define MT19937_Consts

/**
 * @file mt19937_consts.h
 * @brief Constants for the Mersenne Twister (MT19937) random number generator.
 *
 * This header defines the algorithm constants used in the MT19937 implementation,
 * including state size, offsets, and bit masks.
 */

 /**
  * @brief The degree of recurrence (state vector size).
  * 
  * MT19937 uses a state vector of 624 32-bit integers.
  */
#define MT_N 624

/**
 * @brief The middle word, an offset used in recurrence relation.
 * 
 * MT19937 is 397, which defines how far apart two words are in the recurrence relation
 */
#define MT_M 397

/**
 * @brief Most significant bit mask.
 * 
 * Used to extract the upper bit of a 32-bit word.
 */
#define MT_UPPER_MASK 0x80000000U

/**
 * @brief Least significant 32-Bit mask.
 * 
 * Used to extract the lower 31 bits of a 32-bit word.
 */
#define MT_LOWER_MASK 0x7FFFFFFFU

/**
 * @brief Constants vector A for the twist transformation.
 * 
 * This value is used in the tempering step of the algorithm
 */
#define MT_MATRIX_A   0x9908B0DFU

/**
 * @brief Masking Constants specific to temper function
 */
#define MT_D 0xFFFFFFFFU
#define MT_B 0x9d2c5680U
#define MT_C 0xEFC60000U

#endif