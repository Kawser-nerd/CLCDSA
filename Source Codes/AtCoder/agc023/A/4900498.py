_,t=open(0);a=s=0;d={0:1}
for i in t.split():s+=int(i);t=d.get(s,0);a+=t;d[s]=t+1
print(a)