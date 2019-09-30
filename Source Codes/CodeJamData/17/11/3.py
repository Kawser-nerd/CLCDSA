tc = int(input().strip())

for tes in range(tc):
    r, c = tuple(int(x) for x in input().split())
    t = list()
    for i in range(r):
        t.append(list(input().strip()))
    for i in range(r):
        if any(x != "?" for x in t[i]):
            cha = list(x for x in t[i] if x != "?")[0]
            for j in range(c):
                if t[i][j] == '?':
                    t[i][j] = cha
                else:
                    cha = t[i][j]
    row = list(x for x in t if x[0] != "?")[0]
    for i in range(r):
        if t[i][0] == '?':
            t[i] = row
        else:
            row = t[i]
    print("Case #%d:" % (tes+1))
    for i in range(r):
        print("".join(t[i]))
