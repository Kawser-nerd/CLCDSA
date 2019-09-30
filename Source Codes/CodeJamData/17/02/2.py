tnum = int(raw_input())

for ti in range(tnum):
    s = str(int(raw_input())+1)
    for i in range(len(s)):
        if i>0 and int(s[i])<int(s[i-1]):
            break
        if s[i]!='0' and (i==0 or int(s[i])>int(s[i-1])):
            ans = s[:i]+str(int(s[i])-1)+'9'*len(s[i+1:])
    while ans[0]=='0':
        ans = ans[1:]
    print 'Case #{}: {}'.format(ti+1, ans)
