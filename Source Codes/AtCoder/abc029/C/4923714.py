def brute_force_attack(N: int) -> list:
    res = []
    for i in range(3 ** N):
        s = ''
        for _ in range(N):
            d = i % 3
            i //= 3

            if d == 0:
                s = 'a' + s
            elif d == 1:
                s = 'b' + s
            else:  # d == 2
                s = 'c' + s

        res.append(s)
    return res


if __name__ == "__main__":
    N = int(input())
    ans = brute_force_attack(N)
    print('\n'.join(ans))