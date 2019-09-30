def pr_day(y,m,d):
    print(str(y).zfill(4)+'/'+str(m).zfill(2)+'/'+str(d).zfill(2))
Y,M,D = map(int,input().split('/'))
#print(Y,M,D)
if Y % (M*D) == 0:
    #print('OK')
    pr_day(Y,M,D)
else:
    #print('need calculate!')
    pd = 0
    ny = Y
    nm = M
    nd = D
    while True:
        nd += 1
        nc = 0
        if nm in [4,6,9,11]:
            nc = 31
        elif nm == 2:
            if ny % 4 == 0:
                if ny%100 == 0 and ny%400 !=0:
                    nc = 29
                else:
                    nc = 30
            else:
                nc = 29
            if nd == nc:
                nd = 1
                nm += 1
        else:
            nc = 32
        if nd == nc:
            nd = 1
            nm += 1
            if nm == 13:
                nm = 1
                ny += 1
        if ny % (nm*nd) == 0:
            #print('OK')
            pr_day(ny,nm,nd)
            break