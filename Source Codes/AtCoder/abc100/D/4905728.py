import copy
N , M = map(int,input().split())
x_y_z = []
for i in range(N):
	x_y_z.append(list(map(int,input().split())))
temp_ans = [0] * 8
num = 0
for i in range(2):
	x_minusplus = (-1)**i
	for j in range(2):
		y_minusplus = (-1)**j
		for k in range(2):
			temp_x_y_z = []

			z_minusplus = (-1)**k
			temp_x_y_z = copy.deepcopy(x_y_z)
			temp_sum = []

			for l in range(N):
				temp_x_y_z[l][0] *= x_minusplus
				temp_x_y_z[l][1] *= y_minusplus
				temp_x_y_z[l][2] *= z_minusplus
				temp_sum.append(sum(temp_x_y_z[l]))

			temp_sum.sort(reverse = True)
			for l in range(M):
				temp_ans[num] += temp_sum[l]
			
			num += 1
				
				

print(max(temp_ans))