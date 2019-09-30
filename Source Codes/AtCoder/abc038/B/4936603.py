s = list(map(int, input().split()))
t = list(map(int, input().split()))
c = 0
for i in s:
    for j in t:
        if i == j:
            c += 1
print("YES" if c > 0 else "NO")