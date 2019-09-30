n, X = map(int, input().split())
price = [int(i) for i in input().split()]
X_bin = format(X, '0' + str(n) + 'b')
ans = 0
for i in range(n):
    if X_bin[i] == '1':
        ans += price[n-1-i]
print(ans)