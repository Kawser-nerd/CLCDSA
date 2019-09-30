n,x = map(int,input().split())
if x in (1, 2 * n - 1):
    print('No')
    exit()
res = list(range(1, 2 * n))
res = res[x - n:] + res[:x - n]
print('Yes')
print(*res, sep='\n')