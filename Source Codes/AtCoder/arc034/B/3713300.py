N = int(input())
res = []
for n in range(max(N-10000,1),N+1):
    k = n
    s = str(n)
    for c in s:
        n += int(c)
    if n == N:
        res.append(k)
res = sorted(list(set(res)))
print(len(res), *res, sep='\n')