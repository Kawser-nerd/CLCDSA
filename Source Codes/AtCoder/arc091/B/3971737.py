N,K = map(int,input().split())
count = 0
for b in range(K+1,N+1):
    tmp = (N//b)*(b-K) + max(N%b-K+1,0)
    count += tmp
print(count if K > 0 else count - N)