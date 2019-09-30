from bisect import bisect_left

n = int(input())
c = [int(input()) for _ in range(n)]

LIS = [c[0]]
for i in range(len(c)):
    if c[i] > LIS[-1]:
        LIS.append(c[i])
    else:
        LIS[bisect_left(LIS, c[i])] = c[i]

print(n - len(LIS))