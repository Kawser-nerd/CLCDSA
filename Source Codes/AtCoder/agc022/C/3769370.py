N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

if any([a < b for a,b in zip(A,B)]):
    print(-1)
    exit()
if A == B:
    print(0)
    exit()


def reachable(a,b,gr):
    if a == b: return True
    assert a > b
    visited = [0] * (a+1)
    stack = [a]
    while stack:
        v = stack.pop()
        if v == b: return True
        visited[v] = 1
        for to in gr[v]:
            if visited[to]: continue
            stack.append(to)
    return False

permanent_use = []

def need(n):
    gr = [set() for i in range(51)]
    for i in range(51):
        for p in permanent_use:
            gr[i].add(i%p)
        for j in range(1,n):
            gr[i].add(i%j)
    for a,b in zip(A,B):
        if not reachable(a,b,gr):
            return True
    return False

if need(51):
    print(-1)
    exit()

for i in range(50,0,-1):
    if need(i):
        permanent_use.append(i)

ans = 0
for p in permanent_use:
    ans += 2**p
print(ans)