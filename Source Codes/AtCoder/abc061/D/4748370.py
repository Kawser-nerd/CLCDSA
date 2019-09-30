INF = float('inf')

def solve():
    lp = [-INF] * n
    lp[0] = 0

    for i in range(n):
        for a, b, c in es:
            if lp[a] != -INF and lp[b] < lp[a] + c:
                lp[b] = lp[a] + c
                if i == n - 1 and b == n - 1:
                    return 'inf'
    return lp[n - 1]


if __name__ == '__main__':
    n, m = map(int, input().split())
    es = []

    for i in range(m):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        es.append((a, b, c))

    print(solve())