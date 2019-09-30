N = int(input())
a = [int(input()) for i in range(N)]

k = 1
ans = 0
while(True):
    k = a[k-1]
    ans += 1
    if k == 2 or ans == N:
        break
print(ans) if k == 2 else print(-1)