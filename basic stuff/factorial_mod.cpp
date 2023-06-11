long long int  factorial(int n, int m) {
    long long int result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % m;
    }
    return result;
}