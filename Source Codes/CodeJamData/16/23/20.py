first = {}
second = {}
np = 0
em = []
match = []

def ToNo(x, isFirst=True):
    global np, em
    ws = first if isFirst else second
    if x not in ws:
        ws[x] = np
        np += 1
        em += [set()]
    return ws[x]

def dfs(x):
    v[x] = True
    for y in em[x]:
        if match[y] == -1 or (not v[match[y]] and dfs(match[y])):
            match[y] = x
            return True
    return False

for case in range(1, int(raw_input())+1):
    print "Case #%d:"%case, 
    np = 0
    first = {}
    second = {}
    em = []

    n = int(raw_input())
    for i in range(n):
        a, b = raw_input().split()
        em[ToNo(a)].add(ToNo(b, False))
        em[ToNo(b, False)].add(ToNo(a))

    match = [-1]*np
    ans = 0
    for x in first:
        no = ToNo(x)
        v = [False]*np
        if dfs(no):
            ans += 1

    print n-(np-ans)

