N, X = map(int, input().split())
def bisearch(n, l):
    half = (2**(n+2)-3) // 2
    return 0 if l <= 0 else 2**n + bisearch(n-1, min(l - 1 - half, half)) if half < l else bisearch(n-1, l-1)
print(bisearch(N, X))