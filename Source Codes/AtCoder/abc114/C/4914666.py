N=int(input())

def count(i,x,y,z):
	if i > N:
		return 0
	c = 1 if x * y * z > 0 else 0
	c += count(i*10+7, x+1, y, z)
	c += count(i*10+5, x, y+1, z)
	c += count(i*10+3, x, y, z+1)
	return c

print(count(0,0,0,0))