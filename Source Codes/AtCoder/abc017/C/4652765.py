n,m = map(int,input().split())
info = [list(map(int,input().split())) for i in range(n)]

imos = [0]*(m+2)
ans = 0

for i in range(n):
  imos[info[i][0]] += info[i][2]
  imos[info[i][1]+1] -= info[i][2]
  ans += info[i][2]

for i in range(1,m+2):
  imos[i] = imos[i] + imos[i-1]

print(ans-min(imos[1:-1]))