import sys
sys.setrecursionlimit(10**5)
N,M = map(int, input().split())
input = sys.stdin.readline
LRD = [ [int(j) for j in input().split()] for _ in range(M)]

data = [x for x in range(N+1)]
rank = [0]  * (N+1)
diff_weight = [0] * (N+1)

def root(x):
    if data[x] == x:
        return x
    else:
        r = root( data[x] )
        diff_weight[x] += diff_weight[ data[x] ]
        data[x] = r
        return r

def weight(x):
    # _ = root(x)
    return diff_weight[x]


def diff(x,y):
    return weight(y) - weight(x)

def merge(x,y,w):
    w  += weight(x); w -= weight(y)
    x = root(x)
    y = root(y)
    if x == y: return False
    if rank[x] < rank[y]: x,y = y,x; w = -w
    if rank[x] == rank[y]: rank[x] += 1
    data[y] = x
    diff_weight[y] = w
    return True

def issame(x,y):
    return root(x) == root(y)

for i in range(M):
    L,R,D = LRD[i]
    # print(L,R,D)
    if not issame(L,R):
        _  = merge(L,R,D)
    else:
        if diff(L,R) != D:
            print("No")
            exit(0)
            
print("Yes")