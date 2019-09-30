N = int(input())
ans = 0
for miria in range(1,N+1):
    ans += miria*10000/N
print(ans)