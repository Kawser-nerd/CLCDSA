import numpy

N = int(input())

S = [[x for x in input()] for _ in range(N)] 

S_mat = numpy.mat(S)

ret = 0
for A in range(N):
    A_change_list = list(range(A, N))
    A_change_list.extend(list(range(A)))
    moved = S_mat[A_change_list, :]
    if numpy.all(moved == moved.T):
        ret +=1
print(N*ret)