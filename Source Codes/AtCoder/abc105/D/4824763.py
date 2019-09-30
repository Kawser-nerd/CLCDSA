N,M = list(map(int,input().split()))
A = list(map(int,input().split()))

S = [0]
for a in A:
    S.append((S[-1]+a)%M)
d = {}
for i in S[1:]:
    d[i] = d.get(i,0)+1
out = 0
for n in d.values():
    out += n*(n-1)//2
out += d.get(0,0)
print(out)