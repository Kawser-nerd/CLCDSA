n=int(input())
h=n//3600
m=(n%3600)//60
s=(n%3600)%60
h=int(h)
m=int(m)
s=int(s)
if h<10:
    H=str(0)+str(h)
else:
    H=str(h)
if m<10:
    M=str(0)+str(m)
else:
    M=str(m)
if s<10:
    S=str(0)+str(s)
else:
    S=str(s)
print(H+':'+M+':'+S)