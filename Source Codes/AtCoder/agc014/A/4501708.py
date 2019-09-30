def solve(a, b, c, ans):
    if (a, b, c) in s:
        return -1
    if (a % 2) or (b % 2) or (c % 2):
        return ans
    s.add((a, b, c))
    a >>= 1
    b >>= 1
    c >>= 1
    return solve(b + c , c + a, a + b, ans + 1)

if __name__ == '__main__':
    a, b, c = map(int, input().split())
    s = set()
    print(solve(a, b, c, 0))