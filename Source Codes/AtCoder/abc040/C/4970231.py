_,t=open(0)
b,*a=map(int,t.split())
c=b
e=f=0
for g in a:e,f,b,c=min(abs(b-g)+e,abs(c-g)+f),e,g,b
print(e)