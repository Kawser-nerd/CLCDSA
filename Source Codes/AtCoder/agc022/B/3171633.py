n = int(input())

if n == 3:
    print(2,5,63)
    exit()
elif n == 4:
    print(2,5,20,63)
    exit()
elif n == 5:
    print(2,5,20,30,63)
    exit()

ans = [8,9,2,3,4,10,6] + [0 for _ in range(n)]
k = 12
i = 7
while i < n:
    ans[i] = k
    ans[i + 1] = k + 2
    ans[i + 2] = k + 3
    ans[i + 3] = k + 4
    i += 4
    k += 6

ans = ans[:n]

temp = sum(ans) % 6

if temp == 2:
    ans[0] = k
elif temp == 3:
    ans[1] = k
elif temp == 5:
    if ans[n - 1] < k - 2:
        ans[1] = k - 2
    else:
        ans[1] = k + 4

print(' '.join(map(str, ans)))