def solve(string):
    a, b = map(int, string.split())

    def f(a):
        if a % 4 == 1:
            return 1
        if a % 4 == 2:
            return a + 1
        if a % 4 == 3 or a == 0:
            return 0
        return a

    return str(f(a - 1) ^ f(b))


if __name__ == '__main__':
    print(solve(input()))