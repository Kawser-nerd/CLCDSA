N = int(input())
 
d = {}
for i in range(2,N+1):
    tmp = i
    for j in range(2,N+1): 
        while tmp%j==0:
            tmp //= j
            d[j] = d.get(j,0)+1
            
ans = 1
for k in d:
    ans *= d[k]+1
    ans %= 10**9+7
print(ans)