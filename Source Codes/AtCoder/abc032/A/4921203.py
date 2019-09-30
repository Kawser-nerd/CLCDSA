def gcd(a: int, b: int)->int:
    if a < b:
        a, b = b, a
    return a if b == 0 else gcd(b, a % b)


def lcm(a: int, b: int)->int:
    return a * b // gcd(a, b)


def like(a: int, b: int, n: int)->int:
    c = lcm(a, b)
    d = c
    while d < n:
        d += c
    return d


if __name__ == "__main__":
    a = int(input())
    b = int(input())
    n = int(input())
    ans = like(a, b, n)
    print(ans)