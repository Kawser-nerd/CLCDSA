import itertools

N, M = map(int, input().split())

score = [0]*(M+1)
s_sum = 0

for i in range(N):
    l, r, s = map(int, input().split())
    score[(l-1)] += s
    score[r] += -s
    s_sum += s
    
score_list = list(itertools.accumulate(score))
ans = s_sum - min(score_list[:-1])
print(ans)