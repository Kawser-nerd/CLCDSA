s= input()
for i in range(len(s)):
    if s.count(s[i])%2==1:
        print('No')
        exit()
print('Yes')