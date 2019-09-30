d = {}

def nCr(n, r):
    if n < r:
        return 0
    if n == r or r == 0:
        return 1
    if (n, r) in d:
        return d[(n, r)]
    d[(n, r)] = nCr(n - 1, r) + nCr(n - 1, r - 1)
    return d[(n, r)]

if __name__ == '__main__':
    n, a, b = map(int, input().split())
    v = sorted((int(s) for s in input().split()), reverse=True)
    print(sum(v[:a]) / a)
    x = v.count(v[a - 1])
    print(nCr(x, v[:a].count(v[a - 1])) if v[0] > v[a - 1] else sum(nCr(x, i) for i in range(a, b + 1)))