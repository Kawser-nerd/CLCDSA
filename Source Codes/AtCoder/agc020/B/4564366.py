k = int(input())
a = list(map(int, input().split()))

child = 2
cmin = 2
cmax = 2
for ai in a[::-1]:
    if cmin % ai:
        cmin = (cmin // ai + 1) * ai
    cmax = cmax // ai * ai + ai - 1
    if cmin > cmax:
        print(-1)
        exit()

print(cmin, cmax)