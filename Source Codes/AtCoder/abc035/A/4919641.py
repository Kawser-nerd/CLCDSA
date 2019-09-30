def gcd(a: int, b: int)->int:
    if a < b:
        a, b = b, a
    return a if b == 0 else gcd(b, a % b)


def tv(H: int, W: int)->str:
    g = gcd(H, W)
    return '{}:{}'.format(H//g, W//g)


if __name__ == "__main__":
    H, W = map(int, input().split())
    ans = tv(H, W)
    print(ans)