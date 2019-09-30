import sys
input = sys.stdin.readline
N , Q = map(int,input().split())
lrl = [tuple(map(int,input().split())) for _ in range(Q)]
imos = [0] * (N +1)
for lr in lrl:
    imos[lr[0]-1] += 1
    imos[lr[1]] -= 1
s = [0] * N
s[0] = imos[0] % 2
for i in range(1,N):
    s[i] = (s[i-1]+imos[i]) % 2
ans = ''
for j in range(N):
    ans = ans + str(s[j])
print(ans)