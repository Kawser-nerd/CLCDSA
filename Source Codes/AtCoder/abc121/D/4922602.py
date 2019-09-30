def g(a):
    n = a + 1
    if n % 2 == 0:
        return (n // 2) % 2
    else:
        p = (n // 2) % 2
        return p ^ a

def f(a, b):
    if a == 0:
        return g(b)
    else:
        return g(b) ^ g(a-1)

assert f(2, 4) == 5, f(2, 4)
assert f(123, 456) == 435, f(123, 456)
assert f(123456789012, 123456789012) == 123456789012
a, b = map(int, input().split())
print(f(a, b))