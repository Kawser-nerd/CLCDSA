n, x = map(int, input().split())
xlist = [int(n) for n in input().split()]
dis_list = [abs(x - y) for y in xlist]
dis_list = sorted(dis_list)

def gojo(num1, num2):

	if num2 == 0:
		return num1
	else:
		return gojo(num2, num1 % num2)
if n == 1:
	print(dis_list[0])
else:
	gcd = gojo(dis_list[1], dis_list[0])
	for i in range(1, n):
		gcd = gojo(dis_list[i], gcd)
	print(gcd)