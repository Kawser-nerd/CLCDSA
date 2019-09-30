import sys
F = sys.stdin
S = F.readline().replace("A", "1").replace("B", "2").strip("\n")
T = F.readline().replace("A", "1").replace("B", "2").strip("\n")

sSum = [0] * (len(S)+1)
tSum = [0] * (len(T)+1)
for i in range(len(S)):
    sSum[i+1] = sSum[i] + int(S[i])
for i in range(len(T)):
    tSum[i+1] = tSum[i] + int(T[i])

Ans = ""
Q = int(F.readline().strip("\n"))
for _ in range(Q):
    a, b, c, d = map(int, F.readline().strip("\n").split(" "))
    if (sSum[b] - sSum[a-1]) % 3 == (tSum[d] - tSum[c-1]) % 3: Ans += "YES\n"
    else: Ans += "NO\n"
print(Ans)