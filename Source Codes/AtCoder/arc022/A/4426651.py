s = input()
cond = 0
for c in s:
    if cond == 0:
        if c in 'Ii':
            cond += 1
    elif cond == 1:
        if c in 'Cc':
            cond += 1
    elif cond == 2:
        if c in 'Tt':
            cond += 1
print('YES' if cond == 3 else 'NO')