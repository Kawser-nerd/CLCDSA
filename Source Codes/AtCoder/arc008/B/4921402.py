from collections import Counter
N,M = map(int,input().split())
name = input()
kit = input()

cn = Counter(name)
ck = Counter(kit)
for k in cn.keys():
    if k not in ck:
        print(-1)
        exit()

ans = 1
while (cn & ck) != cn:
    ck += Counter(kit)
    ans += 1
print(ans)