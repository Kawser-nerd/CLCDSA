import sys

def main():
    input = sys.stdin.readline
    A, B = map(int, input().split())

    if A+B >= 10:
        return 'error'
    else:
        return A+B


if __name__ == '__main__':
    print(main())