X = input()
flg = 0
X = X.replace('ch', 'C')
choku = ['C', 'o', 'k', 'u']
for i in range(len(X)):
    if X[i] not in choku:
        flg = 1
print('YES' if flg == 0 else 'NO')