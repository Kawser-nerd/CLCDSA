n=input()
s=input();x,a=0,0
for i in s:
	x += 1 if i=='I' else -1
	a=max(a,x)
print(a)