# E
N = int(input())
P_list = list(map(int, input().split()))
X_list = list(map(int, input().split()))

# graph
child_list = [[] for _ in range(N+1)]
for i in range(2, N+1):
    child_list[P_list[i-2]].append(i)

# from root
# minimize local total weight

color1 = [0]+X_list
color2 = [0]*(N+1)

# solve knapsack
def solve_knapsack(L, M):
    min_acc = sum([min(color1[j], color2[j]) for j in L])
    if min_acc > M:
        return -1
    else:
        add_can = M - min_acc
        add_set = set([0])
        for j in L:
            add_j = max(color1[j], color2[j]) - min(color1[j], color2[j])
            add_set_ = set(add_set)
            for s in add_set:
                if s + add_j <= add_can:
                    add_set_.add(s + add_j)
            add_set = add_set_
        
        total = sum([color1[j]+color2[j] for j in L])
        return total - max(add_set) - min_acc

res = "POSSIBLE"

for i in range(N, 0, -1):
    if len(child_list[i]) == 0:
        pass
    elif len(child_list[i]) == 1:
        j = child_list[i][0]
        if min(color1[j], color2[j]) > X_list[i-1]:
            res = "IMPOSSIBLE"
            break
        elif max(color1[j], color2[j]) > X_list[i-1]:
            color2[i] = max(color1[j], color2[j])
        else:
            color2[i] = min(color1[j], color2[j])
    else:
        c2 = solve_knapsack(child_list[i], X_list[i-1])
        if c2 < 0:
            res = "IMPOSSIBLE"
            break
        else:
            color2[i] = c2
    
print(res)