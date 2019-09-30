n, x = map(int, input().split())

def g(a, b):
    if a%b == 0:return b
    return g(b, a%b)

ans = 3*(n-g(n, x))
print(ans)