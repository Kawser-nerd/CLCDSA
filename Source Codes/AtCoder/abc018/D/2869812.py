import itertools
N, M, P, Q, R = (int(i) for i in input().split())

A = [[] * N for i in range(0, N)]
for i in range(0, R):
    x , y , z = (int(i) for i in input().split())
    A[x-1].append((y-1, z))


ls = [i for i in range(0, N)]
it = itertools.combinations(ls, P)

ans = -10000000
for X in it: 
    score = [0] * M
    for i in list(X):
        for y, z in A[i]:
            score[y] += z

    score.sort(reverse = True)

    sum = 0;
    for i in range (0, Q):
        sum += score[i]
    ans = max(ans, sum)
print (ans)