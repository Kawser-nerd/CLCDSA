cache = {}


def fib(n):
    if cache.get(n):
        return cache[n]
    if n == 1 or n == 2:
        return 1
    cache[n-1] = fib(n-1)
    cache[n-2] = fib(n-2)
    return cache[n-1] + cache[n-2]


k = int(input())
print(fib(k+2), fib(k+1))