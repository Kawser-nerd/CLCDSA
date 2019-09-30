# C(800)
# maximize
import numpy as np
import heapq

X, Y, Z = map(int, input().split())
A_np = np.zeros(X+Y+Z, dtype='int')
B_np = np.zeros(X+Y+Z, dtype='int')
C_np = np.zeros(X+Y+Z, dtype='int')

for i in range(X+Y+Z):
    a, b, c = map(int, input().split())
    A_np[i] = a
    B_np[i] = b
    C_np[i] = c
    
# Bronze -> Gold
order_A_C = np.argsort(A_np - C_np)
A_np_s = A_np[order_A_C]
B_np_s = B_np[order_A_C]
C_np_s = C_np[order_A_C]

# base : Bronze -> Silver -> Gold
res_base = C_np_s[:Z].sum() + B_np_s[Z:(Z+Y)].sum() + A_np_s[(Z+Y):].sum()

# left_diff_heap
C_B_heapq = list(C_np_s[:Z] - B_np_s[:Z])
heapq.heapify(C_B_heapq)

plus_left = np.zeros(Y+1, dtype='int')
for k in range(Y):
    r = heapq.heappushpop(C_B_heapq, C_np_s[Z+k] - B_np_s[Z+k])
    plus_left[k+1] = plus_left[k] - r + C_np_s[Z+k] - B_np_s[Z+k]

# right_diff_heap
A_B_heapq = list(A_np_s[(Z+Y):] - B_np_s[(Z+Y):])
heapq.heapify(A_B_heapq)

plus_right = np.zeros(Y+1, dtype='int')
for k in range(Y):
    r = heapq.heappushpop(A_B_heapq, A_np_s[Z+Y-1-k] - B_np_s[Z+Y-1-k])
    plus_right[Y-k-1] = plus_right[Y-k] - r + A_np_s[Z+Y-1-k] - B_np_s[Z+Y-1-k]
    
print((plus_left+plus_right).max() + res_base)