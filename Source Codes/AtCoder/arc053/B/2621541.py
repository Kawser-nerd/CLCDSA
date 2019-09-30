s = input()
m = len(s)
x = {}
for a in s:
    if a in x.keys():
        x[a] += 1
    else:
        x[a] = 1
ls = list(x.values())
ls.sort()

n = 0
for i in ls:
    if i % 2 == 1:
        n += 1
if n == 0:
    print(m)
    exit()
ans = ((m-n) // 2) // n
ans = ans * 2 + 1
print(ans)