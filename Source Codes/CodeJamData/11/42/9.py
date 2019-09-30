from operator import itemgetter
fi = open("input.txt")

maxn = 500
cnt= 0

for run in range(int(fi.readline())):
    R,C,D = map(int,fi.readline().split())
    a = []
    for i in range(R):
        row = map(int,list(fi.readline().strip()))
        a.append(row)
    K = -1
    #print a
    for i1 in range(R):
        for i2 in range(i1+2,R):
            for j1 in range(C):
                j2 = j1+(i2-i1)
                if j2>=C:
                    continue
                cx = (i1+i2)*0.5
                cy = (j1+j2)*0.5
                dx , dy = 0,0
                for i in range(i1,i2+1):
                    for j in range(j1,j2+1):
                        if (i in [i1,i2]) and (j in [j1,j2]):
                            continue
                        dx+=(i-cx)*a[i][j]
                        dy+=(j-cy)*a[i][j]
                        #print a[i][j],dx,dy
                #print i1,i2,j1,cx,cy,dx,dy
                if dx==0.0 and dy==0.0:
                    K = max(K, i2-i1+1)
    if K==-1:
        res = "IMPOSSIBLE"
    else:
        res = K
    print "Case #{0}: {1}".format(run+1,res)