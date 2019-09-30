N = int(input())
A = list(map(int, input().split()))


# ??1+2+...+N??????????
Sum = sum(A)
if Sum % (N * (N + 1) // 2) != 0:
    print('NO')
    exit()


# ????
K = Sum // (N * (N + 1) // 2)

Diff = [A[i] - A[(i - 1)] for i in range(N)]
# ???-1?(N-1)???+(N-1)?????????-1????????+1??????
Diff = [d - K for d in Diff]

for d in Diff:
    if d < 0:
        if d % N != 0:
            print('NO')
            exit()
        else:
            K -= abs(d // N)

if K == 0:
    print('YES')
else:
    print('NO')