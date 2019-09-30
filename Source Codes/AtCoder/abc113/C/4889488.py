N, M = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(M)]
 
now = 0
num = 0
d = dict()
for p, y in sorted(data):
    if now != p:
        now = p
        num = 1
    d[(p,y)] = num
    num += 1
 
for p, y in data:
    print('{:06d}{:06d}'.format(p, d[(p,y)]))