if __name__ == "__main__":
    from collections import Counter
    N = int(input())
    a = list(map(int, input().split()))
    counter = Counter(a)

    if N == 1 and a[0] == 0:
        print(1)
        exit()
    if a[0] != 0 or counter[0] > 1 or counter[1] == 0:
        print(0)
        exit()

    max_v, mod, answer = max(a)+1, 10**9+7, 1

    for i, j in zip(range(max_v), range(1, max_v)):
        prev, current = counter[i], counter[j]
        c1 = pow(pow(2, prev, mod)-1, current, mod)
        c2 = pow(2, current*(current-1)//2, mod)
        answer = answer * c1 * c2 % mod

    print(answer)