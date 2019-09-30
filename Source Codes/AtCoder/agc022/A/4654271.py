s = input()
l = list('abcdefghijklmnopqrstuvwxyz')
for s_ in s:
    l.remove(s_)
if l==[]:
    l.append(s[-1])
    for i in range(len(s)-2,-1,-1):
        if s[i]<max(l):
            for k in l:
                if k>s[i]:
                    print(s[:i]+k)
                    exit()
        l.append(s[i])
    print(-1)
else:
    print(s+l[0])