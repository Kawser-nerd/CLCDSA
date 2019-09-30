import collections

N = int(input())
Units = []
count = 0
relations = []

for i in range(N):
    l,m,s = input().split()
    m = int(m)
    if l not in Units:
        Units.append(l)
        count += 1
        relations = [a + [0] for a in relations]
        relations.append([0 for a in range(count)])
    if s not in Units:
        Units.append(s)
        count += 1
        relations = [a + [0] for a in relations]
        relations.append([0 for a in range(count)])
    relations[Units.index(l)][Units.index(s)] = m
    relations[Units.index(s)][Units.index(l)] = 1/m

dq = collections.deque()

dq.append((1,0))

u = len(Units)

search_flags = [False for i in range(u)]
values = [0 for i in range(u)]
values[0] = 1


while(len(dq) > 0):
    (m,unit) = dq.popleft()
    if search_flags[unit]:
        continue
    search_flags[unit] = True
    l = relations[unit]

    for i in range(u):        
        if l[i] > 0:
            if not search_flags[i]:
                values[i] = m*l[i]
                dq.append((m*l[i], i))

minval = min(values)
newvalues = [round(v/minval) for v in values]

max_u = values.index(minval)
min_u = values.index(max(values))
print(str(1)+Units[max_u]+"="+str(max(newvalues))+Units[min_u])