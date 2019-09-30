S = list(input())
B = 0
W = 0
for i in range(len(S)):
    if S[i] == 'B':
        B += 1
    else:
        W += 1
Num = 0
Count = 0
for i in range(len(S)):
    if S[i] == 'W':
        Count += (i-Num)
        Num += 1
print(Count)