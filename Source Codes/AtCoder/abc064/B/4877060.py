import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))

    return max(A) - min(A)


if __name__ == '__main__':
    print(main())