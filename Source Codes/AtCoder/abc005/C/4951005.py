T = int(input())
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

if N < M:
    print('no')
    quit()


A = sorted(A)
B = sorted(B)


for b in B:
    for i, a in enumerate(A):
        if b - a >= 0 and b - a <= T:
            del A[i]
            break

if N - len(A) == M:
    print('yes')
else:
    print('no')