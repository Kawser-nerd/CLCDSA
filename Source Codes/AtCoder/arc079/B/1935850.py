# -*- coding: utf-8 -*-
import math
K = int(input())

N = 50
As = [N-1 for _ in range(N)]
ind = 0

modk = K % 50
base = 49 + K//50 - modk

ans = []

if modk != 0:
    for i in range(N):
        if i >= N - modk:
            ans.append(base + N + 1)
        else:
            ans.append(base)
    # for i in range(0,modk,1):
    #     ans.append(base + N + 1)
    # for i in range(modk,N,1):
    #     ans.append(base)
else:
    for i in range(N):
        ans.append(49 + K//50)
# for k in range(K):
#     for i in range(N):
#         As[i] -= 1
#     As[ind] += N + 1
#     ind += 1
#     ind = ind % N
# print(N)
# print(*As)
print(N)
print(*ans)