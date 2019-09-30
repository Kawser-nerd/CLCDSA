N, M = map(int, input().split(' '))
a = []
b = []

for i in range(M):
    ai, bi = input().split(' ')
    if ai == '1':
        a.append(bi)
    if bi == str(N):
        b.append(ai)
if len(set(a) & set(b)) > 0:
    print("POSSIBLE")
else:
    print('IMPOSSIBLE')