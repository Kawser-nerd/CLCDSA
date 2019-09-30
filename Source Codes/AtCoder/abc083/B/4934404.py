n,a,b = map(int, input().split())
ans = 0
for i in range(n+1):
    sum = 0
    ans_i = i
    for j in range(5):
        sum += i % 10
        i = i // 10
    if a <= sum <= b:
        ans += ans_i
print(ans)