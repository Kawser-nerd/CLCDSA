import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

def dfs(graph:list, par:int, cur:int, mod:int):
    children = []
    for child in graph[cur]:
        if child == par:
            continue
        
        children.append(child)
        
    if len(children) == 0:
        return 2, 1
    
    else:
        topall = 1
        topwht = 1
        
        for child in children:
            topallchild, topwhtchild = dfs(graph, cur, child, mod)
            
            topwht *= topallchild
            topwht %= mod
            
            topall *= topwhtchild
            topall %= mod
            
        return (topall+topwht)%mod, topwht
    
n = ni()
graph = [[] for _ in range(n)]
MOD = 10**9+7
for _ in range(n-1):
    a,b = li_()
    graph[a].append(b)
    graph[b].append(a)
    
ans, _ = dfs(graph, 0, 0, MOD)

print(ans)