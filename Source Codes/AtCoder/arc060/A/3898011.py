N, A = map(int, input().split(' '))
X = list(map(int, input().split(' ')))
# ans_map[x][y] x+1??????y??????????
ans_map = [[0 for i in range(50*(j+1)+1)] for j in range(N)]
count = 0
for n in X:
    count += 1
    for x in range(0, count)[::-1]:
        for y in range(len(ans_map[x])):
            if ans_map[x][y] != 0:
                ans_map[x+1][y+n] += ans_map[x][y]
    ans_map[0][n] += 1
ans = 0
for i in range(N):
    ans += ans_map[i][A*(i+1)]
print(ans)