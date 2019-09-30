s = input()
t = s[::-1]
for x,y in zip(s,t):
    if x != '*' and y != '*' and x != y:
        print('NO')
        exit()
print('YES')