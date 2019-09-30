import sys
readline = sys.stdin.readline
write = sys.stdout.write

N, M = map(int,input().split())
cities = []
for i in range(M):
    p, y = map(int,readline().split())
    temp = [p, y, i]
    cities.append(temp)
id = [1 for i in range(N)] #?i+1???????????????ID
sortedcities = sorted(cities, key=lambda x:x[1])
for i in range(M):
    sortedcities[i].append(id[sortedcities[i][0]-1])
    id[sortedcities[i][0]-1] += 1
originalcities = sorted(sortedcities, key=lambda x:x[2])
for i in range(M):
    write(str(originalcities[i][0]).zfill(6) + str(originalcities[i][3]).zfill(6) + "\n")