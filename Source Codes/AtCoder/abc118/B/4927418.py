N,M=map(int,input().split())
S=set(range(1,M+1))
for i in range(N):
    K,*A=map(int,input().split())
    S&=set(A)
print(len(S))