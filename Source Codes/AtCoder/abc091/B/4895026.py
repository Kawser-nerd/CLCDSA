n = int(input())
ans = 0
cnt = dict()
for i in range(n):
    s = input()
    try:
        cnt[s] += 1
    except:
        cnt[s] = 1
m = int(input())
for i in range(m):
    s = input()
    try:
        cnt[s] -= 1
    except:
        cnt[s] = -1

for i in cnt.values():
    ans = max(ans, i)
print(ans)