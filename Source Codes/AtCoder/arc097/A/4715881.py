s = input()
K = int(input())
S = set()

for i in range(len(s)):
    S.add(s[i])
    S.add(s[i:i+2])
    S.add(s[i:i+3])
    S.add(s[i:i+4])
    S.add(s[i:i+5])

S = sorted(list(S))
print(S[K-1])