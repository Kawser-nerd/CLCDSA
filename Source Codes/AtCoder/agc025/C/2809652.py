n = int(input())
l = [0]
r = [0]
for _ in range(n):
    l1, r1 = map(int, input().split())
    l.append(l1)
    r.append(r1)

l = sorted(l)[::-1]
r.sort()
result = 0
for i in range( n + 1):
    if l[i] > r[i]:
        result += l[i] - r[i]
print(result * 2)