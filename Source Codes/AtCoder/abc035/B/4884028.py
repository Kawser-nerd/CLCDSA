S = input()
T = int(input())
S1 = S.replace('?', '')
ds = len(S) - len(S1)
x = 0
y = 0
for i in range(len(S1)):
    if S1[i] == 'U':
        y += 1
    elif S1[i] == 'D':
        y -= 1
    elif S1[i] == 'R':
        x += 1
    elif S1[i] == 'L':
        x -= 1
if T == 1:
    print(abs(x) + abs(y) + ds)
else:
    print(max(len(S)%2, abs(x) + abs(y) - ds))