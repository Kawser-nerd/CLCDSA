import sys

def main():
    input = sys.stdin.readline
    A = list(map(str, input().split()))

    ans = A[0][0] + A[1][0] + A[2][0]

    return ans.upper()


if __name__ == '__main__':
    print(main())