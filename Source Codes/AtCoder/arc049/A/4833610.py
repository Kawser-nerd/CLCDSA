*s,=input()
for i in input().split()[::-1]:s.insert(int(i),'"')
print(''.join(s))