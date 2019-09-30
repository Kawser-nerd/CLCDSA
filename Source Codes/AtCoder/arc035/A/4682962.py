s = input()
for (a,b) in zip(s,s[::-1]):
    if a == '*' or b == '*':pass
    else:
        if a == b:pass
        else:
            print('NO')
            break
else:print('YES')