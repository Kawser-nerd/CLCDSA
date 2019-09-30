N = int(input())
S = input()
Edirect = [0]
numE = 0
ans = N

for i in range(N):
    if S[i] == "E":
        numE += 1
    Edirect.append(numE)

for i in range(1, N+1):
    tmp = ((i-1)-Edirect[i-1]) + (Edirect[N]-Edirect[i])
    if tmp < ans:
        ans = tmp

print(ans)