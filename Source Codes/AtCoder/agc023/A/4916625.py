from collections import defaultdict
N = int(input())
A = [int(a) for a in input().split()]

series = [0] * (N + 1)
for i in range(1, N+1):
    series[i] = series[i-1] + i
sumDict = defaultdict(int)
sumDict[0] = 1
sum = 0
for a in A:
    sum += a
    sumDict[sum] += 1

total = 0
for key in sumDict:
    total += series[sumDict[key] - 1]
print(total)