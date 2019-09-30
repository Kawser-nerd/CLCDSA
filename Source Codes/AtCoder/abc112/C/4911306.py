N = int(input())


info = [[0,0,0] for i in range(N)]

for n in range(N):
    info[n][0],info[n][1],info[n][2] = map(int,input().split())

info.sort(key=lambda x:x[2],reverse=True)
for cx in range(101):
    for cy in range(101):
        cnt = 1
        H = info[0][2] + abs(info[0][0]-cx) + abs(info[0][1]-cy)
        for n in range(1,N):
            cnt += 1 
            if info[n][2] != max(H-abs(info[n][0]-cx)-abs(info[n][1]-cy),0):
                break
            if cnt == N:
                print(cx,cy,H)
                exit()