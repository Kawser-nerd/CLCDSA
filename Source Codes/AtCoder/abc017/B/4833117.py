X = input()

X = X.replace('ch', 'C')
ans = 'YES'
for x in X:
    if x not in ['C', 'o', 'k', 'u']:
        ans = 'NO'
        break

print(ans)