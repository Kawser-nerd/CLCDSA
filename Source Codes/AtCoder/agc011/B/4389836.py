N = int(input())
A = list(map(int,input().split()))
A.sort()

c = 0
kind = N
for i,a in enumerate(A):
    if c*2 < a:
        kind = N - i
    c += a
print(kind)