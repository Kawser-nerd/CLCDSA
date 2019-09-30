X = int(input())
ans = []
for b in range(1, 32):
    for p in range(2, 10):
        if b ** p <= X:
            ans.append(b ** p)
print(max(ans))