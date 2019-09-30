n=int(input())
a=[]
for _ in range(n):
	a.append(int(input()))
a.append(0)

def ans():
	if a[0]>0:
		return -1
	else:
		ans=0
		for i in range(n):
			if a[i+1]-a[i]>1:
				return -1
			elif a[i+1]-a[i]<1:
				ans+=a[i]
		return ans

print(ans())