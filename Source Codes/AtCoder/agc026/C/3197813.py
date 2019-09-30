from itertools import product
from collections import defaultdict
n = int(input())
s = input()
sa, sb = s[:n], s[n:][::-1]
a, b, ans = defaultdict(int), defaultdict(int), 0
for p in product(range(2), repeat=n):
    word_a_1, word_b_1, word_a_2, word_b_2 = "", "", "", ""
    for j in range(n):
        if p[j]:
            word_a_1 += sa[j]
            word_b_1 += sb[j]
        else:
            word_a_2 += sa[j]
            word_b_2 += sb[j]
    a[(word_a_1, word_a_2)] += 1
    b[(word_b_1, word_b_2)] += 1
while a:
    key, value = a.popitem()
    ans += value * b[key]
print(ans)