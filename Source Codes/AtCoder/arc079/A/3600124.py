N, M = map(int, input().split())
l1=[False]*(N+1)
l2=[False]*(N+1)


for i in range(M):
    a, b = map(int, input().split())
    if a==1:
        l1[b]=True
    elif b==N:
        l2[a]=True
        
fl=False
for i in range(N):
    if l1[i] and l2[i]:
        fl=True
    
if fl:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')