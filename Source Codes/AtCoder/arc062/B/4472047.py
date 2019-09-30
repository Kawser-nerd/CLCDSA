s = [x == "g" for x in input()]
# p <= g
p = 0
g = 0

def is_g(x):
    return x


cnt = 0
for v in s:
    if is_g(v):
        if p < g:
            p += 1
            cnt += 1
        else:
            g += 1
    else:
        if p >= g:
            g += 1
            cnt -= 1
        else:
            p += 1
print(cnt)