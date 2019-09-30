a,b = map(int,input().split(" "))
ar = [[] for i in range(a+1)]
for i in range(b):
    l = list(map(int,input().split(" ")))
    ar[l[0]].append(l[1])
    ar[l[1]].append(l[0])
for r in ar[1]:
    if a in ar[r]:
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")