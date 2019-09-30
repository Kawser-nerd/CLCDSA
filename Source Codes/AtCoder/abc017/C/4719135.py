N, M = map(int, input().split())

score = [0] * (M+1)
sum_score = 0
for i in range(N):
    l, r, s = map(int, input().split())

    score[l-1] += s
    score[r] -= s
    sum_score += s

for i in range(M):
    score[i+1] += score[i]

print(sum_score - min(score[:-1]))