from sys import stdin

height, width = map(int, input().split())

g = []

for h in range(height):

    l = stdin.readline().split()
    g.append(l)
    g.append(l)

for h in range(height*2):
    print(''.join(map(str, g[h])))