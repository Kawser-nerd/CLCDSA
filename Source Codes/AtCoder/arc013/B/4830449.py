c = int(input())
g = 0
ma = mb = mc = 0
for _ in range(c):
    (a,b,c) = sorted(map(int,input().split()),reverse = True)
    ma = max(ma,a)
    mb = max(mb,b)
    mc = max(mc,c)
else:
    print(ma*mb*mc)