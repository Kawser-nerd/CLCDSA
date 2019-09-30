from sys import stdin
from decimal import Decimal, ROUND_HALF_UP, ROUND_HALF_EVEN
Deg, Dis = [int(x) for x in stdin.readline().rstrip().split()]
Dis_beawfort = Decimal(str(Dis/60)).quantize(Decimal('0.1'), rounding=ROUND_HALF_UP)
# print(Dis_beawfort)
if Dis_beawfort <= 0.2:
	print("C", 0)
else:
	a = Deg/10
	# print(a)
	b = Dis_beawfort
	houi_down = [11.25, 33.75, 56.25, 78.75, 101.25, 123.75, 146.25, 168.75, 191.25, 213.75, 236.25, 258.75, 281.25, 303.75, 326.25]
	houis = ["NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"]
	houi = None
	for i in range(len(houi_down)):
		if houi_down[i] <= a:
			houi = houis[i]
		else:
			break
	if not houi:
		houi = "N"
	if houi == "NNW":
		if a < 348.75:
			pass
		else:
			houi = "N"
	huryoku_down = [0.3, 1.6, 3.4, 5.5, 8.0, 10.8, 13.9, 17.2, 20.8, 24.5, 28.5, 32.7]
	for i in range(len(huryoku_down)):
		if huryoku_down[i] <= float(b):
			huryoku = i + 1
		else:
			break
	print(houi, huryoku)