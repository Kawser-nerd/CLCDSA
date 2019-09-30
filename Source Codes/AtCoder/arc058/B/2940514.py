H, W, A, B = map(int, input().split())

M, S = 10 ** 9 + 7, H + W - 2
fact_n = [0 for i in range(S+1)]
fact_inv = [0 for j in range(S+1)]


def combination(n, r):
    if n == 0 and r == 0:
        return 1
    elif n < r or n < 0:
        return 0

    res = fact_n[n] * fact_inv[r] % M
    return res * fact_inv[n-r] % M


def main():
    fact_n[0] = fact_inv[0] = 1
    for i in range(1, S+1):
        fact_n[i] = fact_n[i-1] * i % M

    fact_inv[S] = pow(fact_n[S], M-2, M)
    for i in range(S-1, 0, -1):
        fact_inv[i] = fact_inv[i+1] * (i+1) % M

    com, bef = combination(S, H-1), 0
    for i in range(B):
        c1, c2 = combination(H-A+i, H-A), combination(S-H+A-i, A-1)
        tmp = (c1-bef) * c2 % M
        bef += c1 - bef
        com -= tmp
        if com < 0:
            com += M

    print(com)


if __name__ == '__main__':
    main()