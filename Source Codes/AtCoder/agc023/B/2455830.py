n = int(input())
s = [input() for i in range(n)]
st = [str().join(s_) for s_ in zip(*s)]

sol = 0

for i in range(n):
    for k in range(n):
        if s[k] != st[k]:
            break
    else:
        sol += 1
    
    s = [s_l[1:]+s_l[0] for s_l in s]
    st = st[1:] + [st[0]]
    
print(sol * n)