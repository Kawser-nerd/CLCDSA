h,w = (int(i) for i in input().split())
a = [input() for i in range(h)]
r,b = [["#"] for i in range(h)],[["."] for i in range(h)]
x = ["#","."]
for i in range(h):
	for j in range(1,w-1):
		if a[i][j]=="#":
			r[i].append("#")
			b[i].append("#")
		else:
			r[i].append(x[i%2])
			b[i].append(x[1-i%2])
	r[i].append(".")
	b[i].append("#")
for i in range(h): print("".join(r[i]))
print()
for i in range(h): print("".join(b[i]))