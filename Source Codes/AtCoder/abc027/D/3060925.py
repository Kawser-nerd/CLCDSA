S = input()
plus, minus = S.count("+"), S.count("-")
M = len(S) - plus - minus
RL = []

for i in range(len(S)):
    if S[i] == "M":
        RL.append(plus - minus)
    elif S[i] == "+":
        plus -= 1
    else:
        minus -= 1
RL.sort()

total = 0
for i in range(M//2):
    total -= RL[i]
for i in range(M//2, M):
    total += RL[i]
print(total)