N, C, K = map(int, input().split())
T = [int(input()) for i in range(N)]
T.sort()
limit = T[0]
answer = 1
counter = 1
for i in range(1,N):
    if T[i] - limit > K or counter == C:
        limit = T[i]
        counter = 1
        answer += 1
    else:
        counter += 1
print(answer)