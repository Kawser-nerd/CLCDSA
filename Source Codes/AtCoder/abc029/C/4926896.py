N = int(input().strip())
c = ['a', 'b', 'c']
tmp = ['']
for _ in range(N):
    tmp = [j + i for i in c for j in tmp]
tmp.sort()
[print(cand) for cand in tmp]