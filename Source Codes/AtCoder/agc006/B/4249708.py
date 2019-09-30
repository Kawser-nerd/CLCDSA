N,x = map(int,input().split())
if x in (1, 2 * N - 1):
    print('No')
    exit()
print('Yes')
if N == 2 and x == 2:
    l = [1, 2, 3]
    print(*l, sep='\n')
elif x == 2:
    l = [4, 1, 2, 3]
    rest = list(range(5, 2 * N))
    m = len(rest) // 2
    l = rest[:m] + l + rest[m:]
    print(*l, sep='\n')
elif x == 2 * N - 2:
    l = [x - 2, x + 1, x, x - 1]
    rest = list(range(1, 2 * N - 4))
    m = len(rest) // 2
    l = rest[:m] + l + rest[m:]
    print(*l, sep='\n')
else:
    l = [x + 2, x - 1, x, x + 1, x - 2]
    rest = list(range(1, x - 2)) + list(range(x + 3, 2 * N))
    m = len(rest) // 2
    l = rest[:m] + l + rest[m:]
    print(*l, sep='\n')