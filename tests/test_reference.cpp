#include <iostream>
#include <vector>
#include <thread>
#include <cassert>

#include "thread_rng_manager.hpp"

constexpr uint32_t MASTER_SEED = 1234;
constexpr uint32_t NUM_THREADS = 4;
constexpr uint32_t NUM_SAMPLES = 10;

int main(){
    ThreadRNGManager rng_mgr(MASTER_SEED);

    std::vector<std::vector<uint32_t>> results(
        NUM_THREADS, std::vector<uint32_t>(NUM_SAMPLES)
    );

    std::vector<std::thread> threads;

    for(uint32_t t = 0; t < NUM_THREADS; t++) {
        threads.emplace_back([&, t]() {
            mt19937& rng = rng_mgr.get(t);
            for (uint32_t i = 0; i < NUM_SAMPLES; i++) {
                results[t][i] =  rng.next();
            }
        });
    }

    for (std::thread& th : threads){
        th.join();
    }

    for (uint32_t i = 0; i < NUM_THREADS; i++){
        for (uint32_t j = i + 1; j < NUM_THREADS; j++){
            assert(results[i] != results[j] &&
                "ERROR : Two threads produced identical sequences!");
        }
    }

    std::cout << "\nThread RNG Manager tests passed\n";
    return 0;
}