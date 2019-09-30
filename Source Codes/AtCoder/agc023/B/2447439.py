n = int(input())

s = []
for _ in range(n):
    s.append(input())
s = s + s

def check(a):
    flag = True
    n = len(a)
    i, j_start = 0, 1
    while flag:
        if i == n - 1:
            break
        for j in range(j_start, n):
            if a[i][j] != a[j][i]:
                flag = False
        i += 1
        j_start += 1
    return flag

ans = 0
for i in range(n):
    if check(s[i:i+n]):
        ans += n
    else:
        pass
print(ans)