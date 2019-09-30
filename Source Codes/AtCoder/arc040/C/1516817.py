# coding: utf-8
field = []
n = int(input())
ans = 0
for i in range(n):
    field.append(list(map(str,input())))
for i in range(n):
    if '.' in field[i]:
        j = n-field[i][::-1].index('.')-1
        field[i]=['o']*n
        if i!=n-1:
            field[i+1][j:]=['O']*len(field[i+1][j:])
        ans+=1
print(ans)