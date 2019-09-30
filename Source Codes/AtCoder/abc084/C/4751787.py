import math
N = int(input())
tc,ts,tf = 0,0,0
C, S, F, =[], [], []
t = 0
for i in range(N-1):
    tc,ts,tf = map(int,input().split())
    C.append(tc)
    S.append(ts)
    F.append(tf)
#print(C,S,F)
for i in range(N-1):
    t = 0
    for j in range(i, N-1):
        if t <= S[j]:
            t = S[j] + C[j]
        else:
            t = math.ceil(t/F[j]) * F[j] + C[j]
    print(t)
print(0)