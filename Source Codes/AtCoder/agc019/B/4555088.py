from collections import Counter
a = input()
c = Counter(a)
n = len(a)

ans = n * (n-1) // 2 + 1
for i in range(26):
    w = chr(ord('a') + i)
    count = c[w]
    if count >= 2:
        ans -= count * (count - 1) // 2

print(ans)