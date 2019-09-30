n = int(input())
S = []
for _ in range(n):
    s = input()
    rev = s[::-1]
    S.append([rev, s])

S.sort()
for i in range(n):
    print(S[i][1])