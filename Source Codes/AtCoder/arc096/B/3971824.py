N, C = map(int, input().split())
Sushi = [[int(info) for info in input().split()] for n in range(N)]
Clocksum = [0 for i in range(N+1)]
AntiClocksum = [0 for i in range(N+1)]
maxClocksum, maxAntisum = [0 for i in range(N+1)], [0 for i in range(N+1)]
for i in range(N): #????????
    Clocksum[i+1] = Clocksum[i] + Sushi[i][1] - Sushi[i][0] 
    AntiClocksum[i+1] = AntiClocksum[i] + Sushi[N-i-1][1] - (C - Sushi[N-i-1][0])
    if i > 0:
        Clocksum[i+1] += Sushi[i-1][0]
        AntiClocksum[i+1] += C - Sushi[N-i][0]
    maxClocksum[i+1] = max(maxClocksum[i], Clocksum[i+1])
    maxAntisum[i+1] = max(maxAntisum[i], AntiClocksum[i+1])
maxCalorie = max(max(Clocksum), max(AntiClocksum))

#???????
ClockToAnticlock = 0
AntiClockToClock = 0
for i in range(N-1):
    ClockToAnticlock = max(Clocksum[i+1] + maxAntisum[N-1-i] - Sushi[i][0], ClockToAnticlock)
    AntiClockToClock = max(AntiClocksum[i+1] + maxClocksum[N-1-i] - (C - Sushi[N-i-1][0]), AntiClockToClock)

print(max(maxCalorie, max(ClockToAnticlock, AntiClockToClock)))