from itertools import permutations
n,m,l = map(int,input().split())
P = list(map(int,input().split()))
v = 0
for p,q,r in permutations(P):
    v = max(
        v,
        (n//p)*(m//q)*(l//r)
        )
print(v)