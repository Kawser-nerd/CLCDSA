N = int(input())
S = input()

W = [0] * N
E = [0] * N
for i in range(1, N):
    if S[i-1] == 'W':
        W[i] = W[i-1] + 1
    else:
        W[i] = W[i-1]

    if S[N-i] == 'E':
        E[N-i-1] = E[N-i] + 1
    else:
        E[N-i-1] = E[N-i]

count = N
for i in range(N):
    count = min(count, W[i] + E[i])
print(count)