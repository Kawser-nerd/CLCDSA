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

n = int(input())
if n == 1:
    print("Not Prime")
    exit()
if n in primes(10*9):
    print("Prime")
else:
    N = list(map(int,list(str(n))))
    if N[-1] % 2 != 0 and N[-1] != 5:
        if sum(N) % 3 == 0:
            print("Not Prime")
        else:
            print("Prime")
    else:
        print("Not Prime")