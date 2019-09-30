import itertools
from collections import Counter

n = int(input())

# ?????????????
# {1: [], 2: [2], 3: [3], 4: [2, 2], 5: [5]}
divs = {}
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

for i in range(1, n + 1):
    divs[i] = []
    x = i
    while x >= 2:
        for p in primes:
            if x % p == 0:
                x //= p
                divs[i].append(p)

# flatten
fdivs = list(itertools.chain.from_iterable(divs.values()))
counts = Counter(fdivs)

ans = 0
# 75==5*5*3
# https://juken-mikata.net/how-to/mathematics/number-of-divisor.html
# 4, 4, 2 ????75????
ge4 = len([c for c in counts.values() if c >= 4])
ge2 = len([c for c in counts.values() if c >= 2])
ans += ge4 * (ge4 - 1) / 2 * (ge2 - 2)

# 75==5*15
# 4, 14 ??
ge14 = len([c for c in counts.values() if c >= 14])
ans += ge14 * (ge4 - 1)

# 75==25*3
# 24, 2 ??
ge24 = len([c for c in counts.values() if c >= 24])
ans += ge24 * (ge2 - 1)

# 75 ==75*1
# 74 ??
ge74 = len([c for c in counts.values() if c >= 74])
ans += ge74

print(int(ans))