def inpl(): return list(map(int, input().split()))
N = int(input())
A = sorted(inpl())
tmp = 1
size = A[0]
for a in A[1:]:
    tmp = tmp * (a <= 2*size) + 1
    size += a
print(tmp)