T = int(input())
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

if N >= M:
    i, j = 0, 0
    while i < M and j < N:
        if B[i] >= A[j] and B[i] <= A[j] + T:
            i += 1
            j += 1
        else:
            j += 1
    if i == M:
        print('yes')
    elif j == N:
            print('no')
else:
    print('no')