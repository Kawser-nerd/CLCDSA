if __name__ == "__main__":
    A, B, C = map(int, [input() for _ in [0]*3])
    mod = 10**9+7
    r_c_1 = pow(A*pow(B, mod-2, mod) + A*pow(C, mod-2, mod) - 1, mod-2, mod)
    c_1 = A*pow(B, mod-2, mod)*r_c_1 % mod
    r_1 = A*pow(C, mod-2, mod)*r_c_1 % mod
    print(r_1-1, c_1-1)