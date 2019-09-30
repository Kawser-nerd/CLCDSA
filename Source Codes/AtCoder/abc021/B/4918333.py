#21
n = int(input())
a, b = map(int, input().split())
k = int(input())
p = list(map(int, input().split()))
p1 = list(set(p))

if len(p)==len(p1) and p.count(a)==0 and p.count(b)==0:
    print('YES')
else:
    print('NO')