N, C, K = map(int, input().split())
Tn = [int(input()) for _ in range(N)]
sTn = sorted(Tn)

bus_count = 1
bus_rider_count = 0
min_T = sTn[0]
for T in sTn:
    if bus_rider_count < C and min_T + K >= T:
        bus_rider_count += 1
    else:
        bus_count += 1
        bus_rider_count = 1
        min_T = T

print(bus_count)