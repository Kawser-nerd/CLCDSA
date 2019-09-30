n, m = map(int, input().split())
if m == 0 or n == 0 or m/n < 2 or m/n > 4:
    print('-1 -1 -1')
else:
    for b in range(2):
        for a in range(n+1):
            if m == ((2 * a) + (4 * (n - a - b)) + (3 * b)):
                print(a, b, n-a-b)