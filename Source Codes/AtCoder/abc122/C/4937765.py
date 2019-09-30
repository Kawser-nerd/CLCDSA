import numpy as np

N,Q=map(int,input().split())
y=input()
arr=np.zeros(len(y))
for i in range(len(y)-1):
    if y[i:i+2]=='AC':
        arr[i+1]=arr[i]+1
    else:
        arr[i+1]=arr[i]
              
for q in range(Q):
    l,r=map(int,input().split())
    print(int(arr[r-1]-arr[l-1]))