n = int(input())
a = list(map(int,input().split()))
a.append(0)
res = 0
p = 0
for i in range(n+1):
    res += abs(p-a[i])
    p = a[i]

for i in range(n):
    ass = res - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]) + abs(a[i+1]-a[i-1])
    print(ass)