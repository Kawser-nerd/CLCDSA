s = input()
t = s[::-1]
for (a,b) in zip(s,t):
    if ('*' not in (a,b)) and a != b:
        print('NO')
        exit()
print('YES')