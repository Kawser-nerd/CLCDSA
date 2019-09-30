# import math
# n,k = list(map(int,input().split()))
# print(math.ceil((n-1)/(k-1)))

n,m = list(map(int,input().split()))
road = {}
whole = []
for i in range(1,n+1):
    whole.append(i)
    road[i] = set()
whole = set(whole)

for i in range(m):
    a,b = list(map(int, input().split()))
    road[a].add(b)
    road[b].add(a)

taka = []
hashi = []
used = set()
no = 0
for x in road:
    l = set()
    r = set()
    l1 = []
    r1 = []
    if x in used:
        continue
    else:
        l.add(x)
        l1.append(x)
        used.add(x)
        for y in whole - road[x]:
            if y not in used:
                r.add(y)
                r1.append(y)
                used.add(y)
    while l1 != [] or r1 != []:
        while r1 != []:
            t = r1.pop()
            for y in whole-road[t]-used-l:
                l.add(y)
                l1.append(y)
                used.add(y)
        while l1 != []:
            t = l1.pop()
            for y in whole-road[t]-used-r:
                    r.add(y)
                    r1.append(y)
                    used.add(y)
    r = list(r)
    l = list(l)

    for i in range(len(l)):
        for j in range(i+1,len(l)):
            if l[j] not in road[l[i]]:
                no = 1
                break
        if no == 1:break
    if no == 1:break
    for i in range(len(r)):
        for j in range(i+1,len(r)):
            if r[j] not in road[r[i]]:
                no = 1
                break
        if no == 1:break
    if no == 1:break

    taka.append(len(l))
    hashi.append(len(r))

if no == 1:print(-1)
else:
    res = [abs(taka[i]-hashi[i]) for i in range(len(taka))]
    res.sort(reverse=-1)
    delta = 0
    for x in res:
        if delta>0:delta-=x
        else:delta+=x
    left = (n+delta)/2
    right = (n-delta)/2
    result = int((left*(left-1)+right*(right-1))/2)
    print(result)