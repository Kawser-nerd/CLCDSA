N, M = [int(s) for s in input().split(' ')]
vote = [0] * M
for _ in range(N):
    answer = [int(s) for s in input().split(' ')][1:]
    for a in answer:
        vote[a-1] += 1
vote_all = 0
for v in vote:
    if v == N:
        vote_all += 1
print(vote_all)