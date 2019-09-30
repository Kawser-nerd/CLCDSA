# -*- coding: utf-8 -*-
line = input().split()
a = int(line[0]) #?100a[g]
b = int(line[1]) #?100b[g]
c = int(line[2]) #??c[g]
d = int(line[3]) #??d[g]
e = int(line[4]) #?100g??????e[g]
f = int(line[5]) #??f[g]

ra = 2
rb = -1
for ai in range(f//(100*a)+2):
    for bi in range(f//(100*b)+2):
        if 100*a*ai+100*b*bi>f:
            break
        for ci in range(f//c+2):
            if 100*a*ai+100*b*bi+c*ci>f:
                break
            elif c*ci>(a*ai+b*bi)*e:
                break
            for di in range(f//d+2):
                sa = 100*a*ai+100*b*bi
                sb = c*ci+d*di
                if sa+sb>f:
                    break
                elif sb>(a*ai+b*bi)*e:
                    break
                elif sa+sb==0:
                    continue
                if sb/(sa+sb) > rb/(ra+rb):
                    ra = sa
                    rb = sb
                    # print(rb/(ra+rb))
                    # print("---")
                    # print(ra,rb)
                    # print(ai,bi,ci,di)

print(ra+rb,rb)