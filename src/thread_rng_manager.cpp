#include "thread_rng_manager.hpp"

ThreadRNGManager::ThreadRNGManager(uint32_t master_seed)
    : _master_seed(master_seed) {}

uint32_t ThreadRNGManager::seed_for(uint32_t thread_index) const{

    uint32_t x = _master_seed ^ (thread_index + 0x9E3779B9u);
    x ^= x >> 16;
    x *= 0x85EBCA6Bu;
    x ^= x >> 13;
    x *= 0xC2B2AE35u;
    x ^= x >> 16;
    return x;
}

mt19937& ThreadRNGManager::get(uint32_t thread_index){
    thread_local mt19937 thread_rng(seed_for(thread_index));
    return thread_rng;
}