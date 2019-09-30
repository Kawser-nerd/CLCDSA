a,b,c,x,y=map(int,input().split())
ans=[0]*3
ans[0]+=min(x,y)*c*2
if x>y:
    ans[0]+=(x-y)*a
else:
    ans[0]+=(y-x)*b
ans[1]+=c*2*max(x,y)
ans[2]+=x*a+y*b
print(min(ans))