def primes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if not is_prime[i]:
            continue
        for j in range(i * 2, n + 1, i):
            is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

prime_lst = primes(55555)

n = int(input())
count = 0
for i in primes(55555):
    if i % 10 == 7:
        print(i)
        count += 1
    if count == n:
        break