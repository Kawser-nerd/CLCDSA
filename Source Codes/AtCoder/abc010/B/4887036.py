N = int(input())
maisu = list(map(int, input().split()))
ans = 0
for i in maisu:
    while (i % 3 == 2 or i % 2 == 0):
        if (i % 3 == 2):
            ans += 1
            i -= 1
        if (i % 2 == 0):
            ans += 1
            i -= 1
print(ans)