N,D,K = list(map(int, input().rstrip().split()))
LR = []
for i in range(D):
    LR.append(list(map(int, input().rstrip().split())))

tribePosition = [0 for i in range(K)]
destination = [0 for i in range(K)]
direction = [0 for i in range(K)]
for i in range(K):
    tribePosition[i],destination[i] = list(map(int, input().rstrip().split()))
    if tribePosition[i] - destination[i] > 0:
        direction[i] = 0
    elif tribePosition[i] - destination[i] < 0:
        direction[i] = 1
        
ans_days = [0 for i in range(K)]
for i in range(D):
    for j in range(K):
        if ans_days[j] == 0:
            if LR[i][0]<=tribePosition[j]<=LR[i][1]:
                if LR[i][0]<=destination[j]<=LR[i][1]:
                    ans_days[j] = i+1
                elif direction[j]:
                    tribePosition[j] = LR[i][1]
                else:
                    tribePosition[j] = LR[i][0]

for i in range(K):
    print(ans_days[i])