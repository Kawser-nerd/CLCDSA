from collections import Counter
n = int(input())

cnt_list = []
for i in range(n):
    cnt_list.append(Counter(input()))

ans = ""

for code in range(ord("a"), ord("a")+27):
    target = chr(code)
    repeat = min([x[target] for x in cnt_list])
    ans += target*repeat

print(ans)