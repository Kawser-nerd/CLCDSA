#constraint 2 <= K <= N <= 50
N,K = map(int,input().split())
locations = [tuple(map(int,input().split())) for _ in range(N)]
## sort by x coordinate
locations.sort()
## search for [i,j] for i-j>= K-1 (* N^2), remenber delta x (i+K) < N
## copy slice locations[i:j+1] and sort by y  (*(N+ NlogN) = * NlogN)
## search for slice, [k,l] where k - l - 1 == K , remenber delta y, calclate delta x * delta y (*N)
## total it should cost O(N^4 * logN), which is 625*1000 * log50 ~ 7*10^6... Python might TLEs?
# print(locations)
minimalArea = (10**18)*5
for i in range(N-K+1):
    for j in range(i+K-1,N):
        deltaX = locations[j][0] - locations[i][0]
        sliced = locations[i:j+1]
        sliced.sort(key= lambda p: p[1])
        # print(sliced)
        length = j-i+1
        if length < K:
            continue
        for k in range(length-K+1):
            deltaY = sliced[k + K - 1][1] - sliced[k][1]
            area = deltaX * deltaY
            # print(deltaX,deltaY,area)
            # if area == 0: continue
            minimalArea = min(area,minimalArea)
print(minimalArea)