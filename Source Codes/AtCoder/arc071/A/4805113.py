n = int(input())
dic = {k:50 for k in "abcdefghijklmnopqrstuvwxyz"}

for _ in range(n):
    S = input()
    for k in dic:
        dic[k] = min(S.count(k),dic[k])

ans = ""
for k in "abcdefghijklmnopqrstuvwxyz":
    ans = ans + k*dic[k]
print(ans)