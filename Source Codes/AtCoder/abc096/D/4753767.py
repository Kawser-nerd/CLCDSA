def d_five_five_everywhere(N):
    def prime_table(n):  # n?????????
        is_prime = [True] * (n + 1)
        is_prime[0] = is_prime[1] = False  # 0?1??????
        for j in range(2, int(n**0.5) + 1):
            if not is_prime[j]:
                continue
            for k in range(j * 2, n + 1, j):
                is_prime[k] = False  # j?????????
        return [i for i in range(n + 1) if is_prime[i]]

    prime_mod5_is_1 = [p for p in prime_table(55555) if p % 5 == 1]
    return ' '.join(map(str, prime_mod5_is_1[:N]))

N = int(input())
print(d_five_five_everywhere(N))