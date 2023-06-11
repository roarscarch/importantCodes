// calculate (base^exponent) mod m using fast power algorithm
long long fastPower(long long base, long long exponent, long long m) {
    long long result = 1;
    base %= m;
    while (exponent > 0) {
        if (exponent & 1) { // if exponent is odd
            result = (result * base) % m;
        }
        exponent >>= 1; // divide exponent by 2
        base = (base * base) % m;
    }
    return result;
}