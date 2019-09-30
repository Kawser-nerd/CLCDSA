from collections import Counter

n = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)
c = Counter(a)

ans = 0
for x in a:
    if c[x] == 0:
        continue
    temp = (1 << x.bit_length()) - x
    c[x] -= 1
    if temp in c.keys():
        if c[temp] > 0:
            c[temp] -= 1
            ans += 1

print(ans)