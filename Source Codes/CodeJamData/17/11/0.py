tc = int(input())

for i in range(1, tc+1):
    print("Case #%d:" % i)
    r, c = map(int, input().split())
    ll = []
    for _ in range(r):
        ll.append(input().strip())
    z = 0
    while ll[z] == "?" * c:
        z += 1
    last = ll[z]
    for i in range(r):
        if ll[i] == "?" * c:
            ls = last
        else:
            ls = ll[i]
        last = ls
        y = 0
        while ls[y] == "?": y += 1
        lc = ls[y]
        tt = []
        for cc in ls:
            if cc == "?":
                print(lc, end = "")
            else:
                print(cc, end = "")
                lc = cc
        print()

