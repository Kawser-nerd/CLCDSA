n=input()
s=input()+"2"
p=input()
a=[0]
i=0
d=1
while i<len(p):
    if s[i]==s[i+1]:
        if a[-1]==0:
            d*=6
        if a[-1]==1:
            d*=2
        if a[-1]==2:
            d*=3
        a.append(2)
        i+=2
    else:
        if a[-1]==0:
            d*=3
        if a[-1]==1:
            d*=2
        a.append(1)
        i+=1
print(d%(10**9+7))