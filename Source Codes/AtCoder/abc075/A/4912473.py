from sys import exit
A,B,C = [int(n) for n in input().split()]
# N = int(input())
# a = [int(input()) for _ in range(N)]
# S = str(input())
# L = len(S)
# T = str(input())
# exit()
if A != B and B == C:
    print(A)
elif A == B and B != C:
    print(C)
else:
    print(B)