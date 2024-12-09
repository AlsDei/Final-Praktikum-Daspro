#include <stdio.h>

#define MOD 1000000007

//! PLEASE PLASE PLASE LET MEE GET WAT I WANT, LET ME GET WAT I WAN DIS TIME
long long matkali(long long i[2][2], long long mat[2][2]){

    long long res[2][2];

    res[0][0] = (i[0][0] * mat[0][0] + i[0][1] * mat[1][0]) % MOD;
    res[0][1] = (i[0][0] * mat[0][1] + i[0][1] * mat[1][1]) % MOD;
    res[1][0] = (i[1][0] * mat[0][0] + i[1][1] * mat[1][0]) % MOD;
    res[1][1] = (i[1][0] * mat[0][1] + i[1][1] * mat[1][1]) % MOD;

    i[0][0] = res[0][0];
    i[0][1] = res[0][1];
    i[1][0] = res[1][0];
    i[1][1] = res[1][1];
}

long long Expo(long long matrix[2][2], long long exp, long long res[2][2]){

    res[0][0] = 1;
    res[0][1] = 0;
    res[1][0] = 0;
    res[1][1] = 1;

    while(exp){
        if(exp % 2 != 0){
            matkali(res, matrix);
        }
        matkali(matrix, matrix);
        exp /= 2;
    }


}

long long fibonacci(long long x, long long y, long long a, long long b, long long n) {
 
    if (n == 0) return x;
    if (n == 1) return y;

    long long matrix[2][2];
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = 1;
    matrix[1][1] = 0;

    long long result[2][2];

    Expo(matrix, n - 1, result);

    return (result[0][0] * y + result[0][1] * x) % MOD;
}

int main() {
    long long x, y, a, b, n;

    scanf("%lld %lld %lld %lld %lld", &x, &y, &a, &b, &n);

    long long res = fibonacci(x, y, a, b, n);

    printf("%lld\n", res);

    return 0;
}
