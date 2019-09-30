n = int(input())

ng = []

for i in range(3):
    ng.append(int(input()))

moves = [-1 for i in range(301)]
moves[0] = 0

for i in range(300):
    if moves[i] >= 0:
        for j in range(1, 4):
            if i + j <= 300 and (i + j) not in ng:
                if moves[i + j] < 0:
                    moves[i + j] = moves[i] + 1
                else:
                    moves[i + j] = min(moves[i + j], moves[i] + 1)

print("YES" if 0 <= moves[n] <= 100 else "NO")