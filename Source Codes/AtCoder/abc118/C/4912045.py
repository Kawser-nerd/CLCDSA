N = int(input())
A = list(map(int, input().split()))

min_idx = None
for i, a in enumerate(A):
    if min_idx is None or A[min_idx] > a:
        min_idx = i

while 1:
    next_min_idx = None

    for i, a in enumerate(A):
        if min_idx == i: continue
        A[i] = a % A[min_idx]

        if A[i] > 0:
            if next_min_idx is None or A[next_min_idx] > A[i]:
                next_min_idx = i

    if next_min_idx is None:
        print(A[min_idx])
        exit()

    min_idx = next_min_idx