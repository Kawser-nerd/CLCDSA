import numpy as np
h,w = map(int,input().split())
n = int(input())
a = list(map(int,input().split()))
mat = np.zeros((h,w),dtype=int)
st = 0
for i in range(len(a)):
    for idx in range(st,st+a[i]):
        mat[idx//w][idx%w]=i+1
    st+=a[i]
for i in range(1,h,2):
    mat[i]=mat[i][::-1]
for i in range(h):
    for j in range(w):
        print(mat[i][j],end=" ")
    print("")