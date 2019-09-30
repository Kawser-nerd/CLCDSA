def a_prime(N):
    if N == 1:
        return 'Not Prime'  # 1????????????

    is_prime = True
    for k in range(2, int(N**0.5) + 1):
        if N % k == 0:
            is_prime = False
            break

    if is_prime:
        ans = 'Prime'
    else:
        n_str = str(N)
        cond = [N % 10 not in (0, 2, 4, 5, 6, 8), sum(map(int, str(N))) % 3 != 0]
        ans = 'Prime' if all(cond) else 'Not Prime'
    return ans

N = int(input())
print(a_prime(N))