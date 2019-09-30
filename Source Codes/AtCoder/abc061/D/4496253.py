n,m = map(int , input().split())

e = []

for i in range(m):
    a,b,c = map(int , input().split())
    e.append((a-1,b-1,c)) 

maxdis = [-float('inf') for i in range(n)]

maxdis[0] = 0
mugen = False

for i in range(n):
    for j in e:
        st,gl,cost = j
        if (maxdis[gl] < maxdis[st]+cost):
            maxdis[gl] = maxdis[st]+cost
            if (i >= n-1 and (gl == n-1)): 
                mugen = True 
                break
if mugen:
    print("inf")

else:
    print(maxdis[n-1])