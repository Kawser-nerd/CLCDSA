def find(A,x):
    p = A[x]
    if p == x:
        return x
    a = find(A,p)
    A[x] = a
    return a
 
def union(A, x, y):
    bx, by = sorted([find(A,x), find(A,y)])
    A[y] = bx
    A[by] = bx

N, Q = map( int, input().split())
V = [ i for i in range(2*N)]
for _ in range(Q):
    w, x, y, z = map( int, input().split())
    x, y = x-1, y-1
    if w == 1:
        if z%2 == 0:
            union(V,x,y)
            union(V,x+N,y+N)
        else:
            union(V,x,y+N)
            union(V,y,x+N)
    else:
        if find(V,x) == find(V,y):
            print('YES')
        else:
            print('NO')