#include <iostream>
#include <vector>
#include <chrono>

int main(int argc, char** argv) {
    long N = 1000000; // valor default
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--N" && i + 1 < argc) {
            N = std::stol(argv[i+1]);
        }
    }

    std::vector<long> A(N), B(N);

    auto t0 = std::chrono::steady_clock::now();

    // loop 1
    for (long i = 0; i < N; i++)
        A[i] = i;

    // loop 2
    for (long i = 0; i < N; i++)
        B[i] = A[i] * 2;

    auto t1 = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(t1 - t0).count();

    std::cout << elapsed << std::endl;
    return 0;
}
