# -*- coding: utf-8 -*-
n,W = map(int, input().split())
iw,v = map(int, input().split())
d = {
    0: [v]
    ,1: []
    ,2: []
    ,3: []
}
for _ in range(1,n):
    w,v = map(int,input().split())
    d[w-iw].append(v)

for i in range(4):
    d[i] = sorted(d[i], reverse=True)

ret = -1
for i in range(min(n,len(d[0]))+1):
    if i*iw>W:
        break
    for j in range(min(n-i,len(d[1]))+1):
        if i*iw+j*(iw+1)>W:
            break
        for k in range(min(n-(i+j),len(d[2]))+1):
            if i*iw+j*(iw+1)+k*(iw+2)>W:
                break
            for l in range(min(n-(i+j+k),len(d[3]))+1):
                if i*iw+j*(iw+1)+k*(iw+2)+l*(iw+3)>W:
                    continue
                V = sum(d[0][:i])+sum(d[1][:j])+sum(d[2][:k])+sum(d[3][:l])
                ret = max(ret, V)
print(ret)