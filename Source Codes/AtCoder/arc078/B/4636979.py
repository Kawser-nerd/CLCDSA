from collections import defaultdict as dd
tree = dd(list)
def dfs_route(tree,start,goal):
    visited = set()
    stack = list()
    visited.add(start)
    stack.append(start)
    while stack:
        node = stack[-1]
        if node == goal:
            return stack
        else:
            child = [x for x in tree[node] if x not in visited]
            if child == []:
                stack.pop()
            else:
                visited.add(child[0])
                stack.append(child[0])
n = int(input())
for _ in range(n-1):
  a,b = map(int,input().split())
  tree[a].append(b)
  tree[b].append(a)
l = dfs_route(tree,1,n)
fl = l[(len(l)-1)//2]
sl = l[(len(l)+1)//2]
tree[fl].remove(sl)
tree[sl].remove(fl)
def gr(tree,start):
    island = set()
    rest = [start,]
    while rest:
        node = rest.pop()
        island.add(node)
        for x in tree[node]:
            if x not in island:
                rest.append(x)
    return(island)
if len(gr(tree,1))*2 > n:
  print("Fennec")
else:
  print("Snuke")