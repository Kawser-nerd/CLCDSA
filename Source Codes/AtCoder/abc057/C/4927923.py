import sys

def f(a, b):
    return max(len(str(a)), len(str(b)))


def main():
    input = sys.stdin.readline
    N = int(input())
    n = int(N**0.5)

    ans = 11
    for i in range(1, n+1):
        if N % i == 0:
            ans = min(ans, f(i, N//i))

    return ans


if __name__ == '__main__':
    print(main())