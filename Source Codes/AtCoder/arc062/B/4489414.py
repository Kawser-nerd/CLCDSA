S = input()

res = 0
if S[0] == 'p':
    res -= 1
p = 0
g = 1
for i in range(1, len(S)):
    if S[i] == 'p' and p < g:
        p += 1
    elif S[i] == 'p' and p >= g:
        g += 1
        res -= 1
    elif S[i] == 'g' and p < g:
        p += 1
        res += 1
    else:
        g += 1
            
print(res)