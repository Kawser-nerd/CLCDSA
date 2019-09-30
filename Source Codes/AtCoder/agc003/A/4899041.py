S=input()
n=S.count('N')
s=S.count('S')
e=S.count('E')
w=S.count('W')
if (n >= 1 and s >= 1) or (n == 0 and s == 0):
  if (e >= 1 and w >= 1) or (e == 0 and w == 0):
    print('Yes')
    exit()
print('No')