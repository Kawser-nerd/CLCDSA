N = int(input())
S = []
for i in range(N):
    S.append(input())

def check(S):
    for i in range(N):
        for j in range(i+1, N):
            if S[i][j] != S[j][i]:
                return 0
    return 1

cnt = 0
for i in range(N):
    cnt += check(S[i:] + S[:i])
print(cnt * N)