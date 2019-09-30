N = int(input())
A = [int(a) for a in input().split()]
maxi = max(A)
mini = min(A)
maxiidx = A.index(maxi)
miniidx = A.index(mini)
print(2 * N - 1)
if maxi >= abs(mini):
    for i in range(N):
        print(maxiidx + 1, i + 1)
    for i in range(1, N):
        print(i, i + 1)
else:
    for i in range(N):
        print(miniidx + 1, i + 1)
    for i in reversed(range(1, N)):
        print(i + 1, i)