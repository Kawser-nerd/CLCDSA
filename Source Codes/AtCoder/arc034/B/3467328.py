n = int(input())
ans = []
for i in range(1,min(154, n+1)):
    x = n-i
    y = list(str(x))
    s = 0
    for j in y:
        s += int(j)
    if s == i:
        ans.append(int(x))
ans.sort()
print(len(ans))
for i in ans:
    print(i)