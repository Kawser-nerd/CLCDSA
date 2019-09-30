n = int(input())
T = list(map(int,input().split()))
V = list(map(int,input().split()))

b = 2
bg = 1.0 / b

M = [] #t = i??????
for i in range(n) :
    for j in range(T[i] * b) :
        M.append(V[i])

R = [0] + T[:]
for i in range(n) :
    R[i+1] += R[i]


for i in range(n) :

    le = R[i] * b
    ri = R[i+1] * b

    
    j = 0
    if i-1 >= 0 and V[i-1] > V[i] :
        while le >= 0 :
            M[le] = min(M[le], V[i] + j*bg)
            #print(M[le])
            j += 1
            le -= 1
    j = 0
    if i+1 < n and V[i+1] > V[i] :
        while ri < len(M) :
            M[ri] = min(M[ri], V[i] + j*bg)
            j += 1
            ri += 1

for i in range(len(M)) :
    M[i] = min(i*bg, (len(M)-i)*bg, M[i])

M += [0]

ans = 0
for i in range(len(M)-1) :
    ans += (M[i] + M[i+1]) * bg * 0.5

print(ans)