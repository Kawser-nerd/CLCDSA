n = int(input())
aSum = 0
abSum = 0
bMin = float('inf')

for i in range(n):
    a, b = list(map(int, input().split()))

    abSum += a
    if a > b:
        bMin = min(bMin, b)
    else:
        aSum += a

if aSum == abSum:
    print(0)
else:
    print(abSum - bMin)