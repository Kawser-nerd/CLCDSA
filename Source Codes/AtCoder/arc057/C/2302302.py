a = int(input())
b = (a+1)*(a+1)
a = a*a
e = 1
n = a
while (a+e-1)//e*e < b:
	n = (a+e-1)//e
	e *= 100
print(n)