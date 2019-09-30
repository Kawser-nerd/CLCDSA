g = 0
for _ in range(int(input())):
    l = list(map(int,input().split()))
    c = sum(l[:4]) + 110/900 * l[4]
    g = max(g,c)
print(g)