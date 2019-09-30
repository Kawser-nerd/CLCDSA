#ABC051 B 
#??
K,S = list(map(int, input().split()))

#??
ans = 0;
for X in range(K+1):
    for Y in range(K+1):
        Z = S-X-Y
        if 0<=Z and Z<=K:
            ans +=1

#??
print(ans)