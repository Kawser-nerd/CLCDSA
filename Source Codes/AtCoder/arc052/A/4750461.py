s = list(input())
p = ['0','1','2','3','4','5','6','7','8','9']
res = ''
for e in s:
    if e in p:
        res += e
print(int(res))