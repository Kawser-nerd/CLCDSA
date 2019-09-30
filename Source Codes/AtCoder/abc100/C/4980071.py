N = int(input())
a = [int(x) for x in input().split()]
ans = 0

for i in range(N):
    while a[i] % 2 == 0:
        ans += 1
        a[i] = int(a[i]/2)
        
print(ans)