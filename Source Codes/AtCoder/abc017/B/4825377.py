X = input()
res = "YES"
i = 0
while i != len(X):
    test = X[i] in ['o','k','u']
    if X[i] == 'c' and i != len(X):
        test = X[i] + X[i+1] == 'ch'
        i += 1
    if not test:
        res = "NO"
        break
    i += 1
print(res)