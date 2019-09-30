from collections import Counter
from itertools import compress, product
N = int(input())
S = input()
s1, s2 = S[:N], S[:N-1:-1]
counter1 = Counter((tuple(compress(s1, bit)), tuple(compress(s1, bitnot))) for bit, bitnot in zip(product(range(2), repeat=N), product(range(1, -1, -1), repeat=N)))
print(sum(counter1[(tuple(compress(s2, bit)), tuple(compress(s2, bitnot)))] for bit, bitnot in zip(product(range(2), repeat=N), product(range(1, -1, -1), repeat=N))))