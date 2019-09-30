n=int(input().strip())
s=[]
su=0
for i in range(n):
    a=int(input().strip())
    s.append(a)
    su+=a
s.sort()

if su%10==0:
    fl=False
    for i in s:
        tm=su-i
        if tm%10!=0:
            su=tm
            fl=True
            break
else:
    fl=True

if fl:
    print(su)
else:
    print(0)