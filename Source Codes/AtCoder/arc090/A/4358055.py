# coding: utf-8


II = lambda: int(input())
MI = lambda: map(int, input().split())
MIL = lambda: list(MI())
MIS = lambda: input().split()


def main():
    N = II()
    A = [MIL(), MIL()]
    ans = 0
    for i in range(N):
        ta = sum(A[0][:i + 1]) + sum(A[1][i:])
        ans = max(ans, ta)
    return ans


if __name__ == "__main__":
    print(main())