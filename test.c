#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to multiply two 2x2 matrices
void multiply(long long A[2][2], long long B[2][2]) {
    long long C[2][2];

    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

    // Copy the result back to A
    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1];
}

// Function to calculate (Matrix M ^ expo)
void power(long long M[2][2], int expo) {
    long long ans[2][2] = { { 1, 0 }, { 0, 1 } }; // Identity matrix

    // Fast exponentiation
    while (expo) {
        if (expo & 1) {
            multiply(ans, M);
        }
        multiply(M, M);
        expo /= 2;
    }

    // Copy the result back to M
    M[0][0] = ans[0][0];
    M[0][1] = ans[0][1];
    M[1][0] = ans[1][0];
    M[1][1] = ans[1][1];
}

// Function to find the nth Fibonacci number
int nthFibonacci(int n) {
    // Base case
    if (n == 0 || n == 1)
        return 1;

    long long M[2][2] = { { 1, 1 }, { 1, 0 } };

    // Raise M to the power of (n - 1)
    power(M, n - 1);

    // The nth Fibonacci number is stored in M[0][0]
    return (int)(M[0][0] % MOD);
}

int main() {
    // Sample input
    int n = 3;

    // Print nth Fibonacci number
    printf("%d\n", nthFibonacci(n));
    return 0;
}
