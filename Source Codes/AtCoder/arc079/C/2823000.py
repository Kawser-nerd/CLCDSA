n = int(input())
aaa = list(map(int, input().split()))
ans = 0
while True:
    flag = True
    for i, a in enumerate(aaa):
        if a >= n:
            flag = False
            k = (a - n) // n + 1
            ans += k
            for j in range(n):
                if i == j:
                    aaa[j] -= k * n
                else:
                    aaa[j] += k
    if flag:
        break
print(ans)