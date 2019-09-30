N = int(input())
A = [int(i) for i in input().split()]
max_i = A.index(max(A))
min_i = A.index(min(A))
abs_max_i = max(max_i,min_i,key = lambda x:abs(A[x]))
print(2*N-2)
for i in range(N):
    [print("{} {}".format(abs_max_i+1, i+1)) if i != abs_max_i else None]
if A[abs_max_i] > 0:
    for i in range(N-1):
        print("{} {}".format(i+1, i+2))
else:
    for i in range(N-1,0,-1):
        print("{} {}".format(i+1, i))