X = int(input())
ans = []
for b in range(1, X//2):
    for p in range(2, X//2):
        t = b**p
        if (t <= X):
            ans.append(t)
if (len(ans) == 0):
    print(1)
else:
    print(max(ans))