X = list(input())

S_count = 0
ans = 0
for i in range(len(X)):
    if X[i] == 'S':
        S_count += 1
    else:
        if S_count:
            ans += 2
            S_count -= 1

print(len(X)-ans)