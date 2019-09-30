X = input()
ans = 0
s = 0
for i in range(len(X)):
    if X[i] == 'S':
        s += 1
    elif s > 0:
        ans += 2
        s -= 1
print(len(X)-ans)