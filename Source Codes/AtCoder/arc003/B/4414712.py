a=int(input())
l = []
for i in range(a):
    t = input()
    s = t[::-1]
    l.append([s,t])
k = sorted(l)
#print(k)
for i in range(a):
    print(k[i][1])