import sys

def main():
    input = sys.stdin.readline
    W, a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)

    return max(0, b - (a + W))


if __name__ == '__main__':
    print(main())