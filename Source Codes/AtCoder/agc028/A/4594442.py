def main28():
    import sys
    N, M = (int(x) for x in input().split())

    if N >= M:
        S = input()
        T = input()
    else:
        T = input()
        S = input()

    def lcm(n, m):
        gcd = 0
        for i in range(1, min(n, m) + 1):
            if n % i == 0 and m % i == 0:
                gcd = i

        return int(n * m / gcd)

    LCM = lcm(N, M)

    a = int(LCM / max(N, M))
    b = int(LCM / min(N, M))

    for i in range(min(N, M)):
        small_index = i * b
        if int(small_index % a) == 0:
            if S[int(small_index / a)] != T[i]:
                print("-1")
                sys.exit()
    print(LCM)

main28()