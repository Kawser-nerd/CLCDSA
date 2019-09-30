height, wide = map(int, input().split())
n = int(input())
anslist = []

a = list(map(int, input().split()))
for i, j in enumerate(a):
    for l in range(j):
        anslist.append(i+1)
for k in range(height):
    t = anslist[k*wide:(k+1)*wide]
    if k % 2 == 1:
        t.reverse()
    print(' '.join(map(str, t)))