import numpy as np

N=int(input())
a_lst=[int(_) for _ in input().split()]
a_arr=np.array(a_lst)
idx=np.absolute(a_arr).argmax() + 1 #1origin

if a_lst[idx-1]==0:
    print(0)
else:
    print(2*N-2)
    for i in range(1, N+1):
        if i != idx:
            print(idx, i)
    if a_lst[idx-1]>0:
        for i in range(1, N):
            print(i, i+1)
    elif a_lst[idx-1]<0:
        for i in range(N, 1, -1):
            print(i, i-1)