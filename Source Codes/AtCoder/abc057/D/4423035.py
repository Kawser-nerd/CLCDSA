import math
N,A,B=map(int,input().split())
v = input().split()
for i in range(N):
    v[i] = int(v[i])

v.sort(reverse=True)

ans1=0
for i in range(A):
    ans1 += v[i]
ans1 /= A
print(ans1)

p = v[A-1]
q = v.count(p)
r = v.index(p)
ans2=0
if not v[0] == v[A-1]:
    #q P A-r
    ans2 = math.factorial(q) // math.factorial(q+r-A) // math.factorial(A-r)
else: # N==q
    for i in range(A,min(q,B)+1):
        # q P i
        ans2 += math.factorial(q) // math.factorial(q-i) // math.factorial(i)
print(ans2)