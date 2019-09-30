n = int(input())
a,b = (int(i) for i in input().split())
if n<=a: print("Takahashi")
elif a==b:
	if n%(a+1)==0: print("Aoki")
	else: print("Takahashi")
else:
	if a>b: print("Takahashi")
	else: print("Aoki")