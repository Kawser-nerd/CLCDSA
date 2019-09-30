abc=[chr(i) for i in range(97,97+26)]
s=input()
for i in abc:
    if i not in s:
        print(i)
        exit()
print('None')