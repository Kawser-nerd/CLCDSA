n = int(input())
a, b = map(int, input().split())
k = int(input())
p = list(map(int, input().split()))

s = set(p)
if len(s) != len(p) or a in p or b in p:
    print('NO')
else:
    print('YES')