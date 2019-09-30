def main():
    m, n, r = map(int, input().split())
    print(solve(m, n, r))

def solve(m, n, r):
    s = 0   # total sold pencils
    t = 0   # number of short pencils

    while r != 0:
        s += r
        t += r
        r = t // m * n
        t = t % m

    return s

main()