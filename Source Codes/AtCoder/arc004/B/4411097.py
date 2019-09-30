N = int(input())
d = []
for i in range(N):
	d.append(int(input()))

d_sum = sum(d)	
d_max = max(d)
if d_max - (d_sum - d_max) > 0:
	D_Min = (d_max - (d_sum - d_max))
else:
	D_Min = 0
print(d_sum)
print(D_Min)