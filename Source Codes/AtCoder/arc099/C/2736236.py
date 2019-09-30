# E
from collections import deque
import numpy as np

N, M = map(int, input().split())
G = dict()
for i in range(1, N+1):
    G[i] = dict()
    for j in range(1, N+1):
        if i != j:
            G[i][j] = 1
            
for _ in range(M):
    a, b = map(int, input().split())
    _ = G[a].pop(b)
    _ = G[b].pop(a)
    
res_con = []

done_list = [1] + [0]*N



core = 1

while core != 0:
    
    # BFS
    queue = deque([core])    
    res_flag = True
    
    size_a = 1
    size_b = 0

    done_list[core] = 1
    while len(queue) > 0:
        a = queue.popleft()
        for b in G[a].keys():
            if done_list[b] == done_list[a]:
                res_flag = False
                break
            elif done_list[b] == 0:
                done_list[b] = -1*done_list[a]
                if done_list[a] == 1:
                    size_b += 1
                else:
                    size_a += 1
                queue.append(b)
    
    res_con.append([size_a, size_b])
    
        
    if res_flag == False:
        break
        
    
    core = 0
    for i in range(1, N+1):
        if done_list[i] == 0:
            core = i
            break
            
# summarize
if res_flag == False:
    res = 0
else:
    res_can_s = np.array([0])
    for rr in res_con:
        a = rr[0]
        b = rr[1]
        res_can_s = np.unique(np.concatenate([res_can_s + a, res_can_s + b]))
    res = ((res_can_s*(res_can_s - 1) // 2) + ((N - res_can_s)*(N - res_can_s - 1) // 2)).min()

if res_flag == False:
    print(-1)
else:
    print(res)