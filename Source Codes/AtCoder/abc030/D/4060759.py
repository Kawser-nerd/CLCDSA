N,a = [int(i) for i in input().split()]
a-=1
k = int(input())
b = [int(i)-1 for i in input().split()]
t = [-1 for i in range(N)]

nowt = 0
while t[a]==-1:
    t[a] = nowt
    a = b[a]
    nowt += 1
loop = max(t) - t[a] + 1

if k <= max(t):
    for i in range(N):
        if t[i]==k:
            print(i+1)
            break
else:
    base = t[a]
    for i in range(N):
        t[i] -= base
    k-=base
    k%=loop
    #import pdb; pdb.set_trace();
    for i in range(N):
        if t[i]==k:
            print(i+1)
            break