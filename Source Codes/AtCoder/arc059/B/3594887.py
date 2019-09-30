s=input()
if len(s)==2 and s[0]==s[1]:print(1,2)
else:
    for i in range(3,len(s)+1):
        a=s[i-3:i]
        if len(set(a))!=3:
            print(i-2,i)
            break
    else:print(-1,-1)