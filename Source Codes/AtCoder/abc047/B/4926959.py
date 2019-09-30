import numpy as np
W, H, N = map(int,input().split())
Map = np.ones((H, W),dtype = int)
for i in range(N):
    x,y,a = map(int,input().split())
    if a == 1:
        Map[:,:x] = 0
    elif a == 2:
        Map[:,x:] = 0
    elif a == 3:
        Map[:y,:] = 0
    else:
        Map[y:,:] = 0
print(Map.sum())