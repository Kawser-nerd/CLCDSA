primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

def get_prime(n, count = {p: 0 for p in primes}):
    for p in primes:
        cp = n
        while cp != 0 and cp % p == 0:
            count[p] += 1
            cp = cp // p
    return count

cnt = {p: 0 for p in primes}
for i in range(1, int(input())+1):
    get_prime(i, cnt)

res = 0
for p1 in primes:
    if cnt[p1] >= 4:
        for p2 in primes:
            if cnt[p2] >= 4 and p1 > p2:
                for p3 in primes:
                    if cnt[p3] >= 2 and p3 != p1 and p3 != p2:
                        res += 1

for p1 in primes:
    if cnt[p1] >= 14:
        for p2 in primes:
            if cnt[p2] >= 4 and p1 != p2:
                res += 1

for p1 in primes:
    if cnt[p1] >= 24:
        for p2 in primes:
            if cnt[p2] >= 2 and p1 != p2:
                res += 1

for p1 in primes:
    if cnt[p1] >= 74:
        res += 1

print(res)