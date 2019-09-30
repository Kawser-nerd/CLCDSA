def get_primes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if not is_prime[i]:
            continue
        for j in range(i * 2, n + 1, i):
            is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

def get_division(N, prime):
    counter = 0
    _prime = prime
    while _prime < N:
        counter += N // _prime
        _prime *= prime
    return counter

N = int(input())

primes = get_primes(N)

counter = 0
counter1 = 0
counter2 = 0
counter3 = 0
counter4 = 0
for prime in primes:
    if get_division(N, prime) >= 74:
        counter += 1
    if get_division(N, prime) >= 24:
        counter1 += 1
    if get_division(N, prime) >= 14:
        counter2 += 1
    if get_division(N, prime) >= 4:
        counter3 += 1
    if get_division(N, prime) >= 2:
        counter4 += 1

total = counter + (counter4 - 1) * counter1 + (counter3 - 1) * counter2 + \
        (counter4 - 2) * counter3 * (counter3 - 1) / 2
print(int(total))