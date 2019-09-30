N = int(input())
W = input().split()
ans = 0
for w in W:
    w = w.replace('.','')
    if w in ('TAKAHASHIKUN','Takahashikun','takahashikun'):
        ans += 1
print(ans)