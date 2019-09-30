h, w = map(int, input().split())
c = []
a = []

for i in range(10):
    c.append(list(map(int, input().split())))
for i in range(h):
    a.append(list(map(int, input().split())))

def search(glaph, start, goal):
    MAX_VAL = 0x10000000
    g_size = len(glaph)
    visited = [False] * g_size
    cost = [MAX_VAL] * g_size
    prev = [None] * g_size
    cost[start] = 0
    prev[start] = start
    now = start
    while True:
        min = MAX_VAL
        next = -1
        visited[now] = True
        for i in range(g_size):
            if visited[i]: continue
            tmp_cost = glaph[now][i] + cost[now]
            if cost[i] > tmp_cost:
                cost[i] = tmp_cost
                prev[i] = now
            if min > cost[i]:
                min = cost[i]
                next = i
        if next == -1: break
        now = next
    return cost[goal]

cost = []
for i in range(10):
    cost.append(search(c, i, 1))
sum = 0
for row in a:
    for element in row:
        if (element != -1):
            sum += cost[element]
print(sum)