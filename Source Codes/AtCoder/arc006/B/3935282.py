N, L = map(int, input().split())
inputs = [list(input()) for _ in range(L+1)]

inputs = inputs[::-1]

start = inputs[0].index('o')
for i in range(L):
    if 0 <= start - 1 and inputs[i+1][start-1] == '-':
        inputs[i][start-1] = ' '
        start -= 2

    elif start + 1 <= 2 * N - 2 and inputs[i+1][start+1] == '-':
        inputs[i][start+1] = ' '
        start += 2

print(start // 2 + 1)