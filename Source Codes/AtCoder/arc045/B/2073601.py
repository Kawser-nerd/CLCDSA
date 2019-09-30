N, M = map(int,input().split())
s = [0]*M
t = [0]*M
for i in range(M):
	s[i],t[i] = map(int,input().split())

imos = [0]*(N+2)
for i in range(M):
	imos[s[i]] += 1
	imos[t[i]+1] -= 1

for i in range(1,N+2):
	imos[i] += imos[i-1]

for i in range(N+2):
	if imos[i] > 1:
		imos[i] = 0

for i in range(1,N+2):
	imos[i] += imos[i-1]

res = []
for i in range(M):
	if imos[t[i]] == imos[s[i] - 1]:
		res.append(i+1)

print(len(res))
for r in res:
	print(r)