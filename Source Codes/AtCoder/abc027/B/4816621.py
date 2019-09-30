n = int(input())
a = list(map(int,input().split()))

ans = 0

if sum(a) % n != 0:
    print(-1)
    quit()

for i in range(n-1):
    if sum(a[:i+1]) != (i+1) * sum(a) / n:
        ans +=1
print(ans)