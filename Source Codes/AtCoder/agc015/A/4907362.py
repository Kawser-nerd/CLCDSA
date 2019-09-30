N, A, B = map(int, input().split())
if A > B: print(0)
elif N == 1 and A != B: print(0)
else:
    minSum = A * (N - 1) + B
    maxSum = A + (N - 1) * B
    print(maxSum - minSum + 1)