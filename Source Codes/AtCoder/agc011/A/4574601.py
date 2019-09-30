visitor, capacity, limit = map(int, input().split())

visitorList = []

for _ in range(visitor):
    arrivalTime = int(input())
    visitorList.append(arrivalTime)
    
visitorList.sort()
start = visitorList[0]
end = start + limit

count = 0
bus = 1

for j in visitorList:
    if start <= j <= end:
        count += 1
        if count <= capacity:
            continue
        else:
            bus += 1
            start = j
            end = j + limit
            count = 1
    else:
        bus += 1
        start = j
        end = j + limit
        count = 1
        
print(bus)