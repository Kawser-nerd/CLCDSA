a = [1, 3, 5, 7, 8, 10, 12]
b = [4, 6, 9, 11]
ans = [0, 0]
x = list(map(int, input().split()))
for i, xi in enumerate(x):
    if xi in a:
        ans[i] = 1
    elif xi in b:
        ans[i] = 2
if ans[0] == ans[1]:
    print('Yes')
else:
    print('No')