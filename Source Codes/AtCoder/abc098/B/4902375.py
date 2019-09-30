N = int(input())
s = input()
ans = 0
for i in range(1, N-1):
    cnt = 0
    X = s[:i]
    Y = s[i:]
    alpX = [0 for j in range(26)]
    alpY = [0 for j in range(26)]
    lenX = i
    lenY = N-i
    for j in range(lenX):
        alpX[ord(X[j])-97] += 1
    for j in range(lenY):
        alpY[ord(Y[j])-97] += 1
    for j in range(26):
        if alpX[j] != 0 and alpY[j] != 0:
            cnt += 1 
    if ans < cnt:
        ans = cnt
print(str(ans))