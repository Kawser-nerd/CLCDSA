import math

if __name__ == '__main__':
    Q = int(input())
    for _ in range(Q):
        a, b = map(int, input().split())
        big = max(a, b)
        small = min(a, b)
        c = math.floor(math.sqrt(a * b))
        if c * c == a * b:
            c -= 1

        if big == small:
            print(2 * big - 2)
        elif big == small + 1:
            print(2 * small - 2)
        elif c * (c + 1) >= a * b:
            print(2 * c - 2)
        else:
            print(2 * c - 1)