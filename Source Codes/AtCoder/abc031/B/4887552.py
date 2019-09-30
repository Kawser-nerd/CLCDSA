Low, High = map(int, input().split())
N = int(input())
for i in range(N):
    time = int(input())
    if (Low <= time and time <= High):
        print(0)
    elif (High < time):
        print(-1)
    else:
        print(Low-time)