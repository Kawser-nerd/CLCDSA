K,N = map(int,input().split())

V = []
W = []
for i in range(N):
    v,w = input().split()
    V.append(v)
    W.append(w)

s = [1,2,3]
import itertools
for lengths in list(itertools.product(s,s,s,s,s,s,s,s,s)):
    ans = True
    for i in range(N):
        v = V[i]
        w = W[i]
        length = 0
        for j in range(len(v)):
            j = int(v[j])
            length += lengths[j-1]
        if length != len(w):
            ans = False
            break
    if not ans:
        continue
    l = ['']*(K+1)
    for i in range(N):
        v = V[i]
        w = W[i]
        for j in range(len(v)):
            j = int(v[j])
            length = lengths[j-1]
            S,w = w[:length],w[length:]
            if l[j] == '':
                l[j] = S
            if S != l[j]:
                ans = False
                break
        if not ans:
            break
    if ans:
        break

for i in range(1,K+1):
    print(l[i])