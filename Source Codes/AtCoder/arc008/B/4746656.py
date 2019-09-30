import collections
N,M = map(int,input().split())
nd = collections.Counter(list(input()))
kd = collections.Counter(list(input()))
#print(nd)
#print(kd)

max_b = -1
for c in nd.keys():
    if not c in kd:
        #print('cannot make!!')
        print(-1)
        break
    else:
        max_b = max(max_b,-(-1*nd[c]//kd[c]))
else:print(max_b)