sn, tn, *s = map(int, open(0).read().split())
sy_oi = [[s[i * 2], s[i * 2 + 1]] for i in range(sn)]
sy_oi.sort(key=lambda x: -x[1])
cho = sy_oi[tn - 1::-1]
zan = sy_oi[tn:]
zn = sn - tn
# ???????????
sydic = {}
for x in cho:
    if x[0] in sydic:
        sydic[x[0]] += 1
    else:
        sydic[x[0]] = 1
ot = sum([x[1] for x in cho])  # ????????
mt = len(sydic)  # ????????
ans = ot + mt ** 2
ci = 0
zi = 0
while 1:
    # ????????????????
    for i in range(ci, tn):
        if sydic[cho[i][0]] > 1:
            sydic[cho[i][0]] -= 1
            ot -= cho[i][1]
            ci = i + 1
            break
    else:
        break
    # ???????????
    for i in range(zi, zn):
        if zan[i][0] not in sydic:
            sydic[zan[i][0]] = 1
            ot += zan[i][1]
            mt += 1
            zi = i + 1
            break
    else:
        break
    # ????????
    ans = max(ans, ot + mt ** 2)
print(ans)