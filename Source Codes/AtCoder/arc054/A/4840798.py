l,x,y,s,d = map(int,input().split())
t1 = (l-abs(d-s))/(x+y) 
t2 = (l-abs(d-s))/max(abs(x-y),0.0000000001) 
t3 = abs(d-s)/(x+y) 
t4 = abs(d-s)/max(abs(x-y),0.0000000001)
if x < y and s <= d:
	print(min(t2,t3))
elif s <= d:
	print(t3)
elif x < y and s > d:
	print(min(t1,t4))
else:
	print(t1)