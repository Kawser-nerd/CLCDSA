def inpl(): return [int(i) for i in input().split()]

N = int(input())
a = inpl()
mini = float('inf')
maxi = -mini
for i in a:
    mini = min(mini, i)
    maxi = max(maxi, i)
print(2*N-1)
if maxi > -mini:
    x = a.index(maxi)+1
    for i in range(1,N+1):
        print(x,i)
    for i in range(1,N):
        print(i,i+1)
else:
    x = a.index(mini)+1
    for i in range(1,N+1):
        print(x,i)
    for i in range(N,1,-1):
        print(i,i-1)