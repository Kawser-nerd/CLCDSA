s=input()
ans='No'
y='Yes'
if ('N' in s and 'S' in s) or ('N' not in s and 'S' not in s):
    if ('E' in s and 'W' in s) or ('E' not in s and 'W' not in s):
        ans=y
print(ans)