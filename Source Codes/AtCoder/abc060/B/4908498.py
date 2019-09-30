import sys

def main():
    input = sys.stdin.readline
    A, B, C = map(int, input().split())

    for i in range(1, B+1):
        if (A * i) % B == C:
            return 'YES'

    return 'NO'


if __name__ == '__main__':
    print(main())