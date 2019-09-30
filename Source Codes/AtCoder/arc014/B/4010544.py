N = int(input())
inputs = [input() for _ in range(N)]

used = [inputs[0]]
for i in range(1, N):
    if inputs[i-1][-1] != inputs[i][0] or inputs[i] in used:
        print('LOSE' if i % 2 == 0 else 'WIN')
        break
    else:
        used.append(inputs[i])
else:
    print('DRAW')