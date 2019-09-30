A, B = map(int, input().split())


# 0 ?? n ??????????? d ?????1??
def count1(n, d):
    mod = n % (2 ** (d + 1))
    n >>= d + 1
    n <<= d
    return n + max(mod - 2 ** d + 1, 0)


def main():
    # (B ?2????1??) - ((A-1) ?2????1??)
    bitcounts = []
    n = B
    d = 0
    while n > 0:
        bitcounts.append(count1(B, d))
        d += 1
        n >>= 1

    n = A - 1
    d = 0
    while n > 0:
        bitcounts[d] -= count1(A - 1, d)
        d += 1
        n >>= 1

    # xor ??10?????????1?????0
    r = 0
    ans = 0
    for bc in bitcounts:
        if bc % 2 == 1:
            ans += 2 ** r
        r += 1
    print(ans)


if __name__ == '__main__':
    main()