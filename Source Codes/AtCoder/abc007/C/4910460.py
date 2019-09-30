import queue

# ??
n, m = map(int, input().split())
s = list(map(int, input().split()))
g = list(map(int, input().split()))
c = [input() for i in range(n)]

# ?????
inf = float('inf')

# s,g?????
s[0]-=1
s[1]-=1
g[0]-=1
g[1]-=1

# ???????
d=[[inf for i in range(m)] for j in range(n)]
d[s[0]][s[1]] = 0

# ?????????
q = queue.Queue()
q.put(s)

# ?????
dyx = [[0,1],[0,-1],[1,0],[-1,0]]

# ????????????
while not q.empty():
    # ???????????
    p = q.get()

    # ??????????????????
    if p == g:
        break

    # ??
    for i in range(len(dyx)):
        # ??????a
        a = [p[0]+dyx[i][0],p[1]+dyx[i][1]]

        # ????????????????????????
        if 0<=a[0]<n and 0<=a[1]<m and c[a[0]][a[1]]!='#' and d[a[0]][a[1]]==inf:
            q.put(a)
            d[a[0]][a[1]]=d[p[0]][p[1]]+1

print(d[g[0]][g[1]])