from sys import stdin
from decimal import Decimal, ROUND_HALF_UP
"""
def rounded_time_before(time): # ?????
	tmp = 10 * Decimal(str(time*0.1)).quantize(Decimal('0'), rounding=ROUND_HALF_UP)
	if time < float(tmp):
		tmp -= 5
	return tmp
def rounded_time_after(time): # ?????
	if str(time)[-1] == "5":
		time -= 1
	tmp = 10 * Decimal(str(time*0.1)).quantize(Decimal('0'), rounding=ROUND_HALF_UP)
	if time > float(tmp):
		tmp += 5
	if str(tmp)[-2:] == "60":
		tmp += 40
	return tmp
"""

N = int(stdin.readline().rstrip())
#SE = [[int(x) for x in stdin.readline().rstrip().split("-")] for _ in range(N)]
SE = [list(map(int, stdin.readline().rstrip().split("-"))) for _ in range(N)]
for i in range(N):
    SE[i][0] = SE[i][0] - SE[i][0] % 5
 
    if (SE[i][1] % 5 != 0):
        SE[i][1] = SE[i][1] - SE[i][1] % 5 + 5
 
    tmp2 = SE[i][1] / 100
 
    if (tmp2 - int(tmp2) > 0.59999):
        SE[i][1] = (int(tmp2) + 1) * 100
    if (SE[i][1] >= 2360):
        SE[i][1] = 2400

state = [0] * 2401
for before, after in SE:
	bf = before
	af = after
	# bf = int(rounded_time_before(before))
	# af = int(rounded_time_after(after))
	state[bf:af+1] = [1]*(af-bf+1)
#print(state)
start_end = []
flag = 0
for i in range(len(state)):
	if flag == 0 and state[i]:
		start_end.append(i)
		flag = 1
	if flag == 1 and not state[i]:
		start_end.append(i-1)
		flag = 0
	if i == 2400 and flag == 1:
		start_end.append(2400)
#print(start_end)
for _ in range(int(len(start_end)/2)):
	print("{}-{}".format(str(start_end.pop(0)).zfill(4), str(start_end.pop(0)).zfill(4)))

# start, end = None, None
# for before, after in sorted(SE):
# 	# bf = int(rounded_time_before(before))
# 	# af = int(rounded_time_after(after))
# 	bf = before
# 	af = after
# 	if not start and not end:
# 		start, end = bf, af
# 	if bf > end: # ??????
# 		print("{}-{}".format(str(start).zfill(4), str(end).zfill(4)))
# 		start, end = bf, af
# 	else:
# 		if af > end:
# 			end = af
# print("{}-{}".format(str(start).zfill(4), str(end).zfill(4)))