n = int(input())

#??????????????
def f(x):
    y = ""
    for i in range(len(x)-1,-1,-1):
        y = y + x[i]
    return y

s = []
for i in range(n):
    d=list(input())
    s.append(f(d))

s.sort()
for i in range(n):
    ass = list(s[i])
    print(f(ass))