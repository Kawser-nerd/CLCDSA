d = input()
if d == "Sunday" or d == "Saturday":
	print(0)
else: 
	D = ["Monday","Tuesday","Wednesday","Thursday","Friday"]
	for i in range(5):
		if D[i] == d:
			print(5-i)