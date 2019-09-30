n = int(input())
a = list(map(int,input().split()))

if sum(a)%n != 0:
    print(-1)
    quit()

x = sum(a)/n 
ans = 0
for i in range(n-1):
    if (i+1)*x != sum(a[:i+1]):
        ans += 1

print(ans)