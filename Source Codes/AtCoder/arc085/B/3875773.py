N, Z, W = map(int, input().split())
A = [int(a) for a in input().split()]

if N == 1: print(abs(A[0]-W))
else: print(max(abs(A[-2]-A[-1]), abs(A[-1]-W)))