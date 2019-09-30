def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def IsPower(n):
    while n % 2 == 0:
        n //= 2
    return n == 1

def solve(num):
    P, Q = map(int, input().split("/"))
    d = gcd(P, Q)
    P //= d
    Q //= d
    if not IsPower(Q):
        ans = "impossible"
    else:
        ans = 1
        while 2 * P < Q:
            ans += 1
            P *= 2
    print("Case #" + str(num) + ":", ans)

T = int(input())
for i in range(T):
    solve(i + 1)


