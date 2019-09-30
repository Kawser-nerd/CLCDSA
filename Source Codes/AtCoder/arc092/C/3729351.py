import sys
N = int(input())
a = [(int(v),i) for i, v in enumerate(input().split())]
ao = sum([v for v, i in a if i%2 and v>0])
ae = sum([v for v, i in a if not i%2 and v>0])
if max(ao, ae)== 0:
    ai = a.index(max(a))
    Ans = [1]*(ai)+list(range(N-ai,1,-1))
    print(max(a)[0])
    print(len(Ans))
    for i in Ans:
        print(i)
    sys.exit()
if ao >= ae:
    print(ao)
    yn = [i for v, i in a if i%2 and v>0]
else:
    print(ae)
    yn = [i for v, i in a if not i%2 and v>0]
listyn = [i in yn for i in range(N)]
Ans = []
while not listyn[0]:
    Ans.append(1)
    listyn = listyn[1:]
while not listyn[-1]:
    Ans.append(len(listyn))
    listyn = listyn[:-1]
while True:
    if len(listyn) == 1:
        break
    if len(listyn) == [2,3]:
        Ans.append(2)
        break
    if listyn[2]:
        Ans.append(2)
        listyn = [True] + listyn[3:]
    else:
        Ans.append(3)
        listyn = [True, False] + listyn[4:]
print(len(Ans))
for i in Ans:
    print(i)