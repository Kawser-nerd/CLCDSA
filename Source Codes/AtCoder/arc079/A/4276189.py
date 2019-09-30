s=set()
N,M=map(int,input().split())
for i in range(M):
    a,b=map(int,input().split())
    s.add((a,b))

for i in range(N):
    if((1,i)in s and (i,N) in s):
        print("POSSIBLE")
        exit()
    
print("IMPOSSIBLE")