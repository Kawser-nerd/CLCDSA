S = [str(_) for _ in input()]
res = ''
for i in S:
    if i.isdigit():
        res += i
print(res)