N = int(input())
A = [int(a) for a in input().split()]

RejectStones = N * (N+1) // 2
if sum(A) % RejectStones != 0: print("NO")
else:
    TotalOperation = sum(A) // RejectStones
    sumcheck = 0
    for i in range(N-1):
        if (TotalOperation - A[i+1] + A[i]) % N != 0 or TotalOperation < A[i+1] - A[i]:
            print("NO")
            break
        else:
            sumcheck += (TotalOperation - A[i+1] + A[i]) // N
    else:
        if (TotalOperation - A[0] + A[-1]) % N != 0 or TotalOperation < A[0] - A[-1]: print("NO")
        else: 
            sumcheck += (TotalOperation - A[0] + A[-1]) // N
            if sumcheck == TotalOperation: print("YES")
            else: print("NO")