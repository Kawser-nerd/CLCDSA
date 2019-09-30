s = set()
e = set()
n, m = map(int, input().split())

for _ in range(m):
    a, b = map(int, input().split())
    if a == 1:
        s.add(b)
    elif b == n:
        e.add(a)
        
print('IM' * (1 - len(s & e)) + 'POSSIBLE')