import sys

N = int(input())
H = [list(map(int, input().split())) for i in range(N)]

H.sort(key=lambda x: x[2], reverse=True)

for i in H:
    x, y, h = i
    for c_x in range(101):
        for c_y in range(101):
            Height = h + abs(x-c_x) + abs(y-c_y)
            for j in range(N):
                if H[j][2] != max(Height-abs(H[j][0]-c_x)-abs(H[j][1]-c_y), 0):
                    break
                if j == N-1:
                    print(c_x, c_y, Height)
                    sys.exit()