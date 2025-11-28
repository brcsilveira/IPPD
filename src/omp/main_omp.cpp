#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <omp.h>

int main(int argc, char** argv) {
    long N = 1000000;
    std::string version = "naive"; // padrão = versão ingênua

    // parse de argumentos
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--N" && i + 1 < argc) {
            N = std::stol(argv[i+1]);
        }
        if (std::string(argv[i]) == "--version" && i + 1 < argc) {
            version = argv[i+1];
        }
    }

    std::vector<long> A(N), B(N);

    auto t0 = std::chrono::steady_clock::now();

    if (version == "naive") {
        // -----------------------------
        //   VERSÃO INGENUA (errada)
        //   duas regiões paralelas separadas
        // -----------------------------
        #pragma omp parallel for
        for (long i = 0; i < N; i++)
            A[i] = i;

        #pragma omp parallel for
        for (long i = 0; i < N; i++)
            B[i] = A[i] * 2;
    }

    else if (version == "optimized") {
        // -----------------------------
        //   VERSÃO OTIMIZADA (correta)
        //   uma região paralela com dois loops dentro
        // -----------------------------
        #pragma omp parallel
        {
            #pragma omp for
            for (long i = 0; i < N; i++)
                A[i] = i;

            #pragma omp for
            for (long i = 0; i < N; i++)
                B[i] = A[i] * 2;
        }
    }

    auto t1 = std::chrono::steady_clock::now();
    double elapsed = std::chrono::duration<double>(t1 - t0).count();

    std::cout << elapsed << std::endl;
    return 0;
}
