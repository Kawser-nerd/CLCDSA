N,M=map(int,input().split())

L=[]
for i in range(N):
    L.append(i+1)

P=0

for i in range(M):
    d=int(input())
    for j in range(N):
        if L[j]==d:
            P,L[j]=L[j],P
            break

for i in range(len(L)):
    print(L[i])