h,w,d = map(int, input().split())


tab = [ [0,0] ]*(w*h)

for hi in range(h):

    t = list(map(int,input().split()))

    for wi in range(w):
        tab[ t[wi]-1 ] = [hi, wi]

#print(tab)


cost = [0]*(w*h)
for i in range(d, w*h):
    a = tab[i-d]
    b = tab[i]

    cost[i] = abs( a[0]-b[0] ) + abs( a[1]-b[1] ) + cost[i-d]

#print(cost)

q = int(input())

for i in range(q):
    l, r = map(int, input().split())

    print(cost[r-1] - cost[l-1])