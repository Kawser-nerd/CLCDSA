def run():
	a=[int(i) for i in raw_input().split()]
	v=[False]*10000
	for i in range(2,6):
		for j in range(2,6):
			for k in range(2,6):
				v[1]=True
				v[i]=True
				v[j]=True
				v[k]=True
				v[i*j*k]=True
				v[i*j]=True
				v[i*k]=True
				v[j*k]=True
				if v[a[0]] and v[a[1]] and v[a[2]] and v[a[3]]:
					print str(i)+str(j)+str(k)
					return
raw_input()
print "Case #1:"
t=int(raw_input().split()[0])
while t:
	t-=1
	run()

