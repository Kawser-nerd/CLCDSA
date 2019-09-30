def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def solve(N, PD, PG):
    g = gcd(PD, 100)
    a, b = PD // g, 100 // g
    if b <= N and not (PG == 100 and PD != 100) and not (PG == 0 and PD != 0):
        return "Possible"
    else:
        return "Broken"

def main():
    T = int(input())
    for i in range(1, T + 1):
        N, PD, PG = map(int, input().split())
        ans = solve(N, PD, PG)
        print('Case #%d: %s' % (i, ans))

if __name__ == '__main__':
    main()

