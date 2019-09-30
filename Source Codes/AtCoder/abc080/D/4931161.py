from operator import itemgetter
n, c = map(int, input().split())
tmp_info = [list(map(int, input().split())) for i in range(n)]

tmp_info = sorted(tmp_info, key=itemgetter(2,1))
info = []
for i in range(n):
    if not info:
        info.append(tmp_info[i])
    elif info[-1][1] == tmp_info[i][0] and info[-1][2] == tmp_info[i][2]:
        info[-1][1] =tmp_info[i][1]
    else:
        info.append(tmp_info[i])
info = sorted(info, key=itemgetter(1))
n = len(info)
li = []

for i in range(n):
    li = sorted(li, reverse=True)
    for j in range(len(li)):
        if info[i][0] > li[j]:
            li[j] = info[i][1]
            break
    else:
        li.append(info[i][1])
        
print(len(li))