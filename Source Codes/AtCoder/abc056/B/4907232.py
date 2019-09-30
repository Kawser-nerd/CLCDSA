w,a,b=map(int,input().split())
print(0 if a<=b<=a+w or b<=a<=b+w else abs(a-b)-w)