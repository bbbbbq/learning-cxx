#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    Fibonacci() : cached(2) {
        cache[0] = 0;
        cache[1] = 1;
    }

    unsigned long long get(int i) {
        if (i < cached) {
            return cache[i];
        }
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
