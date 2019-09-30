d = {}
B = input().split()
for i in range(10):
    d[B[i]] = str(i)
N = int(input())

a = []
for _ in range(N):
    t = input()
    u = ''
    for i in t:
        u += d[i]
    a.append([int(u), t])
a.sort(key = lambda x: x[0])
for v in a:
    print(v[1])