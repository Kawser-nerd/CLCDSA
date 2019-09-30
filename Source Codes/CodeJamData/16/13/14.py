
# coding: utf-8

# 4
# 4
# 2 3 4 1
# 4
# 3 3 4 1
# 4
# 3 3 4 3
# 10
# 7 8 10 10 9 2 9 6 3 3
# 
# Case #1: 4
# Case #2: 3
# Case #3: 3
# Case #4: 6

# In[35]:

def find_longest(node):
    global visited
    visited[node] = True
    if node not in graph:
        return 1
    max_child = 0
    for i in graph[node]:
        if visited[i]:
            continue
        max_child=max(max_child, find_longest(i))
    return max_child + 1


# In[33]:

def dfs(node):
    vis = [0 for i in range(len(FF))]
    vis[node] = 1
    
    size = 1
    tmp = node
    while True:
        tmp = FF[tmp]
        if tmp == node:
            return size
        if vis[tmp]==1:
            return 0
        vis[tmp] = 1
        size += 1
    return 0


visited = []
graph = {}
Q = int(input())
for q in range(Q):
    N = int(input())
    FF = list(map(int, input().split()))
    FF.insert(0, -1)
    
    graph = {}
    visited = [False for i in range(N+1)]
    
    for i in range(1, len(FF)):
        if FF[i] not in graph:
            graph[FF[i]] = []
        graph[FF[i]].append(i)
        
    double = 0
    for i in range(1, N+1):
        if i == FF[FF[i]] and not visited[i]:
            visited[i] = True
            visited[FF[i]] = True
            dou = find_longest(i) + find_longest(FF[i])
            double += dou
    
    for i in range(1, N+1):
        if not visited[i]:
            double = max(double, dfs(i))
            
    print("Case #{}: {}".format(q+1, double))


# In[29]:

# In[ ]:



