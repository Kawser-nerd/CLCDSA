N, C, K = map(int, input().split())
T = [int(input()) for i in range(N)]
T.sort()
answer = 0
while len(T) > 0:
    limit = T[0] + K
    counter = 0
    while counter < C:
        if len(T) == 0:
            break
        if T[0] > limit:
            break
        del T[0]
        counter += 1
    answer += 1
print(answer)