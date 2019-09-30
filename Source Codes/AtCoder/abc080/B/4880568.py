N = input()

x = int(N)
fx = sum(list(map(int, list(N))))

if x%fx == 0:
    print('Yes')
else:
    print('No')