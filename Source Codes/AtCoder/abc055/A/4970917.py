import sys

def main():
    input = sys.stdin.readline
    N = int(input())

    x = 800 * N
    y = 200 * (N // 15)

    return x - y


if __name__ == '__main__':
    print(main())