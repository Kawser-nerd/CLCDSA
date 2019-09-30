N, M = map(int, input().split())
a_list = []
b_list = []
for i in range(M):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)

par = [i for i in range(N+1)]
rank = [0]*(N+1)
size = [1] * (N + 1)

def find(x):
    if par[x] == x:
        return par[x]
    else:
        par[x] = find(par[x])
        return par[x]


def unite(x, y):
    x_par = find(x)
    y_par = find(y)
    if x_par == y_par:
        return
    if rank[x_par] < rank[y_par]:
        par[x_par] = y_par
        size[y_par] += size[x_par]
    else:
        par[y_par] = x_par
        size[x_par] += size[y_par]
        if rank[x_par] == rank[y_par]:
            rank[x_par] += 1


def bool_func(x, y):
    if find(x) == find(y):
        return True
    else:
        return False


ans_list = []      
ans = int(N*(N-1)/2)
for i in range(M):
    ans_list.append(ans)
    a = a_list[M-1-i]
    b = b_list[M-1-i]
    p = size[find(a)]
    q = size[find(b)]
    if bool_func(a, b):
        pass
    else:
        ans -= p*q
        unite(a, b)

for i in range(M):
    print(ans_list[M-1-i])