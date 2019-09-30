n,c = map(int,input().split())

data = []

for i in range(n):
    s,t,h = map(int,input().split())
    data.append((s,t,h))

data.sort()

record = []

for s,t,h in data:
    flag = False
    for track in record:
        if track[0]<=s and track[1]==h:
            track[0]=t
            track[1]=h
            flag = True
            break
        elif track[0]<s and track[1]!=h:
            track[0]=t
            track[1]=h
            flag = True
            break
    if not flag:
        record.append([t,h])

print(len(record))