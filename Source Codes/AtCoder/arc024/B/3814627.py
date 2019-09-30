from itertools import groupby

N = int(input())
COLOR = [int(input()) for _ in range(N)]

colors = [[k, len(list(g))] for k, g in groupby(COLOR)]
if len(colors) == 1:
    print(-1)
    exit()
if colors[0][0] == colors[-1][0]:
    colors[0][1] += colors[-1][1]
    colors.pop()

# print(list(map(lambda x: x[1], colors)))
print(-(-max(map(lambda x: x[1], colors))//2))