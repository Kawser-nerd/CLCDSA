w,a,b=map(int,input().split())
if min(a,b)+w>=max(a,b):
    print(0)
else:
    print(max(a,b)-min(a,b)-w)