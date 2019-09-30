# coding: utf-8
# ?????
#a = int(raw_input())
# ?????????????
import heapq
N = int(input())

Rmax = 0
Rmin = 1000000001
Bmax = 0
Bmin = 1000000001

data = sorted([sorted(list(map(int, input().split()))) for i in range(N)],key=lambda x:x[0])

tempBlues = sorted([d[1] for d in data])
tempReds = [d[0] for d in data]
heapq.heapify(tempReds)

Rmin = data[0][0]
Rmax = data[N-1][0]
Bmax = max(tempBlues)
Bmin = min(tempBlues)

minValue = (Rmax - Rmin)*(Bmax - Bmin)
Bmin = Rmin

for i in range(N):
    heapMin = heapq.heappop(tempReds)
    if heapMin == data[i][0]:
        heapq.heappush(tempReds, data[i][1])
        if  data[i][1] > Rmax:
            Rmax = data[i][1]
        if (Rmax - tempReds[0])*(Bmax - Bmin) < minValue:
            minValue = (Rmax - tempReds[0])*(Bmax - Bmin)
    else:
        break

print(minValue)