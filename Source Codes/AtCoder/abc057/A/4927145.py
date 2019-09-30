import sys

def main():
    input = sys.stdin.readline
    A, B = map(int, input().split())

    return (A + B) % 24


if __name__ == '__main__':
    print(main())