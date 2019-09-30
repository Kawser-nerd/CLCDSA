n = int(input())

s = 0
m = 10**9+7
same = True
for _ in range(n):
    a,b = map(int, input().split())
    if a > b:
        m = min(m, b)
    s += a
    same &= a==b
if same:
    m = s
print(s-m)