N, M = map(int, input().split())
A = [list(map(int, input().split())) for i in range(N)]

S_list = {}
for i in range(M):
    S_list[i+1] = 0

participants = 10000
while len(S_list) > 0:
    for i in range(N):
        for j in range(M):
            if A[i][j] in S_list:
                S_list[A[i][j]] += 1
                break
    participants = min(participants,max(S_list.values()))
    if participants == 1:
        break
    for i in S_list.keys():
        if S_list[i] == max(S_list.values()):
            del S_list[i]
            break
    for i in S_list.keys():
        S_list[i] = 0

print(participants)