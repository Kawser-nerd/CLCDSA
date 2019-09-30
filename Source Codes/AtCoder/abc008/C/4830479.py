n = int(input())
c = []
ans = 0
for i in range(n):
    c.append(int(input()))
lis = []
for i in range(n):
    temp = 0
    for j in range(n):
        if c[i] % c[j] == 0:
            temp += 1
    if temp % 2 == 0:
        ans += 0.5
    else:
        ans += (temp + 1)/(2 * temp)
print(ans)