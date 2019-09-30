import sys
sys.setrecursionlimit(100000)

N, M = map(int, input().split())

count = [0] * (N)
E = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    E[a - 1].append(b - 1)
    E[b - 1].append(a - 1)
    count[a - 1] += 1
    count[b - 1] += 1

count_sum = 0
count4 = 0
count6 = 0
node = 0

check = [False] * N

for i, temp in enumerate(count):
    if temp % 2 == 1:
        print("No")
        exit()
    else:
        if temp >= 4:
            count4 += 1
            check[i] = True
            node = i
        if temp >= 6:
            count6 += 1
        count_sum += temp

def dfs(v, first, depth):
    global E, check

    ret = 0
    for next_v in E[v]:
        if depth >= 2 and next_v == first:
            return 1
        elif not check[next_v]:
            check[next_v] = True
            ret += dfs(next_v, first, depth + 1)

    return ret

if count4 >= 3 or count6 >= 1:
    print("Yes")
elif count4 == 2:
    ret = dfs(node, node, 0)
    if ret > 0:
        print("Yes")
    else:
        print("No")
else:
    print("No")