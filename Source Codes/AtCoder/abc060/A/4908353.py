import sys

def main():
    input = sys.stdin.readline
    A, B, C = map(str, input().split())

    if A[-1] == B[0] and B[-1] == C[0]:
        return 'YES'
    else:
        return 'NO'


if __name__ == '__main__':
    print(main())