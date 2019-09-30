def main():
    R = 10**9+7
    N = int(input())
    a = list(map(int, input().split(" ")))

    if a[0] != 0:
        return 0

    amax = max(a)
    h = [0] * (amax+1)
    for i in a:
        h[i] += 1
    if h[0] != 1:
        return 0

    ans = 1
    b = 1
    for i in h[1:]:
        if i == 0:
            return 0
        ans *= pow(2, i * (i - 1) // 2, R)
        ans %= R
        ans *= pow(pow(2, b, R) - 1, i, R)
        ans %= R
        b = i
    return ans


if __name__ == '__main__':
    print(main())