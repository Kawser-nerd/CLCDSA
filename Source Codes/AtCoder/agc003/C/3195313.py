# coding:utf-8

INF = float('inf')


def inpl(): return list(map(int, input().split()))


N = int(input())
A = [int(input()) for _ in range(N)]
B = sorted(A)
C = A[::2] + B[1::2]
D = set(C)

print(N - len(D))