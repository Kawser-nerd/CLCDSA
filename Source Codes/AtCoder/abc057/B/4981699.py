N,M = map(int,input().split())

ab_a = []
for i in range(0,N):
    ab = list(map(int,input().split()))
    ab_a.append(ab)

cd_a = []
for i in range(0,M):
    cd = list(map(int,input().split()))
    cd_a.append(cd)

for i in range(0,N):
    mnh = 10 ** 10
    point = 100
    h = 0
    for h in range(0,M):
        tmp = abs(cd_a[h][0] - ab_a[i][0]) + abs(cd_a[h][1] - ab_a[i][1])
        if tmp < mnh:
            mnh = tmp
            point = h
    print(point + 1)