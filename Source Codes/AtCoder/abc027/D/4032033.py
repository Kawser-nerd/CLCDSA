s = input()
N = len(s)
pl, mi = 0, 0
rec = []
m = 0
for i in range(N - 1, -1, -1):
    if s[i] == "M":
        rec.append(pl - mi)
        m += 1
    elif s[i] == "+":
        pl += 1
    else:
        mi += 1

rec = sorted(rec)
print(sum(rec[m // 2:]) - sum(rec[:m // 2]))