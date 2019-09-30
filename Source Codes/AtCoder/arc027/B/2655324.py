"""UNION FIND"""

N = 26

parent = [i for i in range(N)]
rank = [1]*(N)

def getroot(x):
    global parent
    if parent[x] == x:
        return x
    else:
        root = getroot(parent[x])
        parent[x] = root
        return root

def is_group(x,y):
    return getroot(x) == getroot(y)

def union(x, y):
    global rank
    rootx = getroot(x)
    rankx = rank[rootx]
    rooty = getroot(y)
    ranky = rank[rooty]
    if rankx > ranky:
        parent[rooty] = rootx
    else:
        parent[rootx] = rooty
        rank[rooty] = max(rank[rooty], rank[rootx]+1)

"""UNION FIND"""

n = int(input())
s = [input() for _ in range(2)]

determined = [False]*N
used = [False]*N

to_int = lambda x: ord(x)-ord('A')
is_alpha = lambda x: ord('A') <= ord(x) <= ord('Z')

head = None
for i in range(n):
    if is_alpha(s[0][i]):
        used[to_int(s[0][i])] = True
        if is_alpha(s[1][i]):
            used[to_int(s[1][i])] = True
            union(to_int(s[0][i]), to_int(s[1][i]))
        else:
            determined[to_int(s[0][i])] = True
        if i == 0:
            head = to_int(s[0][i])
    else:
        if is_alpha(s[1][i]):
            used[to_int(s[1][i])] = True
            determined[to_int(s[1][i])] = True
            if i == 0:
                head = to_int(s[1][i])
        else:
            pass

if head is not None:
    head = getroot(head)

for i in range(26):
    used[getroot(i)] |= used[i]
    determined[getroot(i)] |= determined[i]
ans = 1
for i in range(26):
    if used[i] and getroot(i) == i:
        if determined[i]:
            pass
        elif head == i:
            ans *= 9
        else:
            ans *= 10
print(ans)