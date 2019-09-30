n,v,w,l=map(int,input().split());t=0
for _ in[0]*n:g=(l-t)/v;t=l;l+=g*w
print(l-t)