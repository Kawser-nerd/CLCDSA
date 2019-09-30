N, Z, W = map(int, input().split())
*A, = map(int, input().split())
if N == 1:
    print(abs(A[0] - W))
else:
    print(max(abs(A[-1] - W), abs(A[-2] - A[-1])))