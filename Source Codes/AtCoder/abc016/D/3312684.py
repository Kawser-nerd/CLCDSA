ax, ay, bx, by = map(int, input().split())
n = int(input())
pos = [list(map(int, input().split())) for i in range(n)]

pos.append(pos[0])

a = by - ay
b = ax - bx
c = - ax * (by - ay) - ay * (ax - bx)

ans = 0
for i in range(n):
    if (a * pos[i+1][0] + b * pos[i+1][1] + c) * (a * pos[i][0] + b * pos[i][1] + c) < 0:
        A = pos[i+1][1] - pos[i][1]
        B = pos[i][0] - pos[i+1][0]
        C = - pos[i][0] * (pos[i+1][1] - pos[i][1]) - pos[i][1] * (pos[i][0] - pos[i+1][0])
        if (A * ax + B * ay + C) * (A * bx + B * by + C) < 0:
            ans += 1

print(ans // 2 + 1)