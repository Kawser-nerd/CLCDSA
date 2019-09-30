n, s = [int(input()) for _ in range(2)]
def f(b, n):
    if n < b:
        return n
    return f(b, n // b) + n % b

if n == s:
    print(n + 1)
    exit()

for i in range(2, int(n ** .5) + 1):
    if s == f(i, n):
        print(i)
        exit()

for i in reversed(range(1, int(n ** .5) + 1)):
    b = (n - s) // i + 1
    if b > 1 and s == f(b, n):
        print(b)
        exit()
print(-1)