def solve(n):
    if n == 0:
        return "0"
    p = 2
    s = []
    while n != 0:
        if n % p == 0:
            s.append(0)
        else:
            n -= (p // 2)
            s.append(1)
        p *= -2
    return "".join(map(str, s[::-1]))

assert solve(-9) == "1011"
assert solve(123456789) == "11000101011001101110100010101"
assert solve(0) == "0"
n = int(input())
print(solve(n))