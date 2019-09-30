from operator import itemgetter
n,m = map(int,input().split())

info = [list(map(int,input().split())) for i in range(m)]
info = sorted(info,key = itemgetter(1))

ans = 0
cut_pos = -1
for i in range(m):
    if cut_pos <= info[i][0]:
        ans += 1
        cut_pos = info[i][1]
print(ans)