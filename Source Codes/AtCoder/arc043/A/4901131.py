def main():
    n, a, b = map(int, input().split())
    s = [int(input()) for _ in range(n)]
    print(*solve(s, n, a, b))

def solve(s, n, a, b):
    mi = min(s)
    ma = max(s)
    avg = sum(s) / n

    if mi == ma:
        return (-1,)
    
    p = b / (ma - mi)
    q = a - avg * p

    return p, q

main()