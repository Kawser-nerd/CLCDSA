import sys

def main():
    input = sys.stdin.readline
    A = list(map(int, input().split()))

    if A[1] - A[0] == A[2] - A[1]:
        return 'YES'
    else:
        return 'NO'


if __name__ == '__main__':
    print(main())