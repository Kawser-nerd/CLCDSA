n = int(input())
k = int(input())
x = list(map(int,input().split()))
kyori = 0

for i in x:
	if i <= abs(k-i):
		kyori += i*2
	else:
		kyori += abs(k-i)*2
print(kyori)