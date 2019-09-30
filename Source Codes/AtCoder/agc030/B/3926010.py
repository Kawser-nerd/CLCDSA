import math
L, N = map(int, input().split())
X = [None for i in range(N)]
DistAntiClock, DistClock = [0 for i in range(N+1)], [0 for i in range(N+1)]
for i in range(N):
    X[i] = int(input())
    DistAntiClock[i+1] = DistAntiClock[i] + 2 * X[i]
for i in range(N):
    DistClock[i+1] = DistClock[i] + (L - X[-1-i]) * 2

maxLength = max(X[N-1], L - X[0])
for i in range(1, N):
    finIndex = math.ceil((i + N)/2)
    if (i + N) % 2 == 0:
        AntiClockLength = DistAntiClock[finIndex] - DistAntiClock[i-1] - X[finIndex-1] + DistClock[N - finIndex] 
        ClockLength = DistClock[finIndex] - DistClock[i-1] - (L-X[-finIndex]) + DistAntiClock[N - finIndex]
    else:
        AntiClockLength = DistAntiClock[finIndex - 1] - DistAntiClock[i-1] + DistClock[N - finIndex + 1] - (L - X[finIndex - 1])
        ClockLength = DistClock[finIndex - 1] - DistClock[i-1] + DistAntiClock[N - finIndex + 1] - X[N - finIndex]
    maxLength = max(max(AntiClockLength, ClockLength), maxLength)

print(maxLength)