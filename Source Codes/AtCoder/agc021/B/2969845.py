import math
import cmath

#def angle(center, left, right):
#	bunshi = (left[0] - center[0]) * (right[0] - center[0]) + (left[1] - center[1]) * (right[1] - center[1]) ** 2
#	bunbo = math.sqrt(((left[0] - center[0]) ** 2 + (right[0] - center[0]) ** 2) * ((left[1] - center[1]) ** 2 + (right[1] - center[1]) ** 2))
#	theta = bunshi / bunbo
#	return 1 - math.acos(theta) / 2 * (math.pi)

def arg(center, point):
	return cmath.phase(complex(point[0] - center[0], point[1] - center[1]))


n = int(input())
dots = [list(map(int, input().split())) for _ in range(n)]

if n == 2:
	print(0.5)
	print(0.5)
else:
	ans = []
	for d in dots:
		arg_list = []
		for e in dots:
			if d == e:
				continue
			else:
				arg_list.append(arg(d, e))
		arg_list.sort()
		convex = False
		if arg_list[-1] - arg_list[0] <= math.pi:
			convex = True
			theta = arg_list[-1] - arg_list[0]
			ans.append(0.5 - theta / (2 * math.pi))
		else:
			for i in range(len(arg_list) - 1):
				if arg_list[i + 1] - arg_list[i] >= math.pi:
					convex = True
					theta = arg_list[i + 1] - arg_list[i]
					ans.append(theta / (2 * math.pi) - 0.5)
			if convex == False:
				ans.append(0)

	for a in ans:
		print(a)