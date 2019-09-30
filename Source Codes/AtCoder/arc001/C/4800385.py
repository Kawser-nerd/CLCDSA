A,B = map(int,input().split())

ds = [-10,-5,-1,1,5,10]
ans = 0
mem = set([A])
while 1:
    if B in mem:
        print(ans)
        exit()
    ans += 1
    mem2 = set()
    for a in mem:
        for d in ds:
            if not -15 < a+d < 55: continue
            mem2.add(a+d)
    mem = mem2