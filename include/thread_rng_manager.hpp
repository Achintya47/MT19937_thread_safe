/**
 * @file ThreadRNGManager.hpp
 * @brief Declaration of ThreadRNGManager for managing per-thread PRNGs.
 * @author Achintya
 * @date 2026-01-07
 */

#ifndef THREAD_RNG_MANAGER
#define THREAD_RNG_MANAGER

#include <cstdint>
#include <mt19937.hpp>

/**
 * @class ThreadRNGManager
 * @brief Manages per-thread instances of the mt19937 PRNG.
 *
 * This class provides deterministic random number generation
 * across multiple threads by deriving unique seeds from a
 * master seed. Each thread can access its own mt19937 instance
 * via the get() method.
 *
 * The design ensures reproducibility and independence of
 * random sequences across threads.
 */
class ThreadRNGManager{
    private:
        /**
         * @brief Computes a unique seed for a given thread.
         *
         * @param thread_index Index of the thread (0-based).
         * @return A 32-bit unsigned integer seed derived from the master seed.
         */
        uint32_t seed_for(uint32_t thread_index) const;

        /**
         * @brief Master seed used to derive per-thread seeds.
         */
        uint32_t _master_seed;

    public:
        /**
         * @brief Constructs the manager with a given master seed.
         *
         * @param master_seed The seed used to initialize all thread-specific generators.
         */
        explicit ThreadRNGManager(uint32_t master_seed);

        /**
         * @brief Retrieves the PRNG instance for a given thread.
         *
         * @param thread_index Index of the thread (0-based).
         * @return Reference to the mt19937 generator associated with the thread.
         */
        mt19937& get(uint32_t thread_index);
};

#endif