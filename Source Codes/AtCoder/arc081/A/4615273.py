import sys
sys.setrecursionlimit(10**9)
N = int(input())
A = list(map(int, input().split()))
A = sorted(A, reverse=True)


def chouhoukei(count, ans, num):
    if count == 4:
        return ans
    else:
        if num >= N - 1:
            return 0
        if A[num] == A[num + 1]:
            return chouhoukei(count + 2, ans * A[num], num + 2)
        else:
            return chouhoukei(count, ans, num + 1)


print(chouhoukei(0, 1, 0))