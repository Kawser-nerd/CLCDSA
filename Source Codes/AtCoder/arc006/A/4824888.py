s=input().split()
t=input()
r=input().split()
if s==r:
    print(1)
elif len(set(s+[t])&set(r))==6:
    print(2)
else:
    f=8-len(set(s)&set(r))
    if f<6:
        print(f)
    else:
        print(0)