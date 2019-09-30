T = input()
for t in range(T):
    data = map(int, raw_input().split())
    N = data[0]
    Pd = data[1]
    Pg = data[2]
    gcd = 1
    for d in range(2, 101):
        if Pd%d==0 and 100%d==0:
            gcd = d
    poss = True
    if (100/gcd) > N:
        poss = False
    elif Pg==100 and Pd<100:
        poss = False
    elif Pg==0 and Pd>0:
        poss = False
    ans = 'Possible' if poss else 'Broken'
    print 'Case #%d: %s' %(t+1, ans)
