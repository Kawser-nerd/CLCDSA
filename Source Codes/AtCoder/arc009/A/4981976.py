N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]
ans = 0
for a,b in src:
    ans += a*b
ans *= 1.05
print(int(ans))