def dist(x1, y1, x2, y2):
    return ((x1 - x2)**2 + (y1 - y2)**2)**0.5


def dist_high(index1, index2):
    return max(dist(
            xyr[index1][0],
            xyr[index1][1],
            xyr[index2][0],
            xyr[index2][1]) - (xyr[index1][2] + xyr[index2][2]), 0)


def min_value_index(array):
    min_value = float("inf")
    min_index = -1
    for i, v in array:
        if min_value > v:
            min_value = v
            min_index = i
    return min_value, min_index

stx, sty, enx, eny = map(int, input().split())
n = int(input())
xyr = [[stx, sty, 0]] + [list(map(int, input().split())) for x in range(n)] + [[enx, eny, 0]]

nodes = {x: float("inf") for x in range(len(xyr))}
nodes[0] = 0
now = 0

while now != (len(xyr) - 1):
    for i in nodes.keys():
        if i == now:
            continue

        nodes[i] = min(nodes[i], nodes[now] + dist_high(now, i))
    del nodes[now]
    now = min_value_index(nodes.items())[1]
print(nodes[n + 1])