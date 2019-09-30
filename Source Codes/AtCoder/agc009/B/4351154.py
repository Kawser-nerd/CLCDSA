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

def dfs(v: int, graph: list) -> int:
    if graph[v] == []:
        return 0
    
    else:
        ret = -1
        cands = []
        for ch in graph[v]:
            cands.append(dfs(ch, graph))
            
        cands.sort(reverse=True)
        
        for idx, cand in enumerate(cands):
            ret = max(ret, idx+1 + cand)
            
        return ret
    

n = ni()
graph = [[] for _ in range(n)]

person = 1
for _ in range(n-1):
    ai = ni()-1
    graph[ai].append(person)
    
    person += 1
    
ans = dfs(0, graph)
print(ans)