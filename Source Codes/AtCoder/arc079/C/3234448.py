n = int(input())
a = [int(i) for i in input().split()]
def f(x):
	k = 0
	for i in a: k+=(i+x-n)//(n+1)+1
	return k<=x
for i in range(max(0,sum(a)-n*(n-1)),51*(10**16)):
	if f(i): break
print(i)