N = int(input())
P = list(map(int,input().split()))
P2 =[0]*(N+1)

i = N-1
T = 0

for j in range(N):
    P2[P[j]] = j+1

while i >= 0:
    if P2[i] > P2[i+1]:
        T = 1
        f = i+1
        i = i-1
        break
    i = i-1
    

while i > 0:
    if (P2[i+1]-P2[i])*(P2[i]-P2[f])*(P2[f]-P2[i+1]) > 0:
        T = T+1
        f = i+1
    i = i-1

print(T)