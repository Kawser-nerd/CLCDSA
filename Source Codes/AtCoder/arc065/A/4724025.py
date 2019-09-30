s=input()
i=len(s)

while True:
    if i==0:
        print('YES')
        break
    if 6<i and s[i-7:i] == 'dreamer':
        i-=7
        continue
    if 5<i and s[i-6:i] == 'eraser':
        i-=6
        continue
    if 4<i and s[i-5:i] in ['dream','erase']:
        i-=5
        continue
    print('NO')
    break