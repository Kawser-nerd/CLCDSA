N = int(input())
J = list(map(int,input().split()))
L = sorted([[J[i],i+1] for i in range(N)],reverse=True)
for i in range(N):
    print(L[i][1])