# coding:utf-8

import sys

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


n = II()
A = LI()

ans = 0
right = 0
num_xor = 0
num_and = 0
for left in range(n):
    while right < n and num_xor ^ A[right] == num_and + A[right]:
        num_xor ^= A[right]
        num_and += A[right]
        right += 1

    ans += right - left

    if left == right:
        right += 1
    else:
        num_xor ^= A[left]
        num_and -= A[left]

    # print(left, right, ans)

print(ans)