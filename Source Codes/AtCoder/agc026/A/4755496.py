import numpy as np

N = int(input())
a = [int(_) for _ in input().split()]
List = np.array([])
tmp = 0
cnt = 0

for i in a:
    if i == tmp:
        cnt += 1
    else:
        List = np.append(List,cnt)
        cnt = 1
        tmp = i
List = np.append(List,cnt)

print(int(sum(List//2)))