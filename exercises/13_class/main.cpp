#include "../exercise.h"

class Fibonacci {
    size_t cache[16];
    int cached;

public:
    // Implement the constructor
    Fibonacci() : cached(2) {
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i < 16; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    }

    // Implement the get method
    size_t get(int i) {
        if (i < 0 || i >= 16) {
            throw std::out_of_range("Index out of range");
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
