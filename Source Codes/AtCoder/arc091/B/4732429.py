N,K=map(int,input().split())
a = 0
for b in range(1,N+1):
    p=N//b
    a+= p*max(0,b-K)
    a+= max(0,N%b-K+1)
    #print(b,a)
#print(a,K)
print(a if K!=0 else a-N)