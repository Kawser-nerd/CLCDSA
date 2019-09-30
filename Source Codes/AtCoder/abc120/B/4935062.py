a,b,k = map(int,input().split())
c = []
for i in range(min(a,b)):
    if a%(i+1) == 0 and b%(i+1) == 0:
        c.append(i+1)
print(c[-k])