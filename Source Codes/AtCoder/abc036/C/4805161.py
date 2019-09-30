n = int(input())
a = [int(input()) for i in range(n)]
d = {}
for i, ai in enumerate(sorted(list(set(a)))):
    d[ai] = i
for ai in a:
    print(d[ai])