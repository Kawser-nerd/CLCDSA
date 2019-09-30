n = int(input())
a = list(map(int, input().split()))

ans = [0]*n

b = []

for i, x in enumerate(a):
    b.append([-x, i])

b.sort()

c = []
p = b[0]
x = [-b[0][0], b[0][1], 1]
for i in range(1, n):
    if -b[i][0] == x[0]:
        x[2] = i+1
    else:
        c.append(x)
        x = [-b[i][0], b[i][1], i+1]
c.append(x)

s = 0
t = c[0][1]
for i in range(len(c)-1):
    x = (c[i][0]-c[i+1][0])*c[i][2]
    t = min(t, c[i][1])
    ans[t] += x
    s += x
ans[min(t, c[-1][1])] += sum(a)-s

for x in ans:
    print(x)