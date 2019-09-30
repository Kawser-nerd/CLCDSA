N, X = map(int, input().split())
x = list(map(int, input().split()))
x = list(map(lambda x: abs(X - int(x)), x))

def gcd(x, y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)
        
if len(x) < 2:
    print(x[0])
else:
    D = gcd(x[0], x[1])
    for i in range(2, N):
        D = gcd(D, x[i])

    print(D)