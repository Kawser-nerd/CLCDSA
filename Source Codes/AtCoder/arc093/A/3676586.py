n = int(input())
a = list(map(int, input().split()))

s = 0
for i in range(n-1):
    s += abs(a[i+1] - a[i])
s += abs(a[0]) + abs(a[-1])

for i in range(n):
    mae = 0 if i == 0 else a[i-1]
    ato = 0 if i == n-1 else a[i+1]
    q = abs(a[i] - mae) + abs(ato - a[i])
    w = abs(ato - mae)
    print(s - q + w)