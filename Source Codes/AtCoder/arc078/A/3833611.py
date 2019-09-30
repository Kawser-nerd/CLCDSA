N = int(input())
a = list(map(int, input().split(' ')))

total = sum(a)
now = a[0]
ans = abs(total - 2*now)
for i in range(1, len(a)-1):
    now += a[i]
    ans = min(abs(total - 2*now), ans)
print(ans)