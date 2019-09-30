N, X = map(int, input().split())
def bisearch(n, l):
    if l <= 0:
        return 0
    half = (2**(n+2)-3) // 2
    if half < l:
        return 2**(n) + bisearch(n-1, min(l - 1 - half, half))
    else:
        return bisearch(n-1, l-1)

print(bisearch(N, X))