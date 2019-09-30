n, m = map(int, input().split())
x=list(map(int, input().split()))
def solve(x):
    if m<=n:
        return 0
    x=sorted(x)
    l=sorted([x[i+1]-x[i] for i in range(m-1)], reverse = True)
    return x[m-1]-x[0]-sum(l[:n-1])
print(solve(x))