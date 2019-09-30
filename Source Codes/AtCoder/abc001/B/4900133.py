meter = int(input())

if 0 <= meter < 100:
	vv = "00"
elif 100 <= meter < 1000:
	vv = "0"+str(int(meter / 100))
elif 1000 <= meter <= 5000:
	vv = int(meter / 100)
elif 6000 <= meter <= 30000:
	vv = int((meter / 1000) + 50)
elif 35000 <= meter <= 70000:
	vv = int((((meter / 1000) -30) / 5) + 80)
elif 70000 < meter <= 100000:
	vv = 89

print(vv)