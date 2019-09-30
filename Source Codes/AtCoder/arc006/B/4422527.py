N , L = map(int,input().split())
data = []
for i in range(L):
	data.append(list(input()))
		
temp_leader = list(input())
leader = temp_leader.index("o")

for i in range(L):
	if leader != 2 * (N - 1) and data[L - 1 - i][leader + 1] == "-":
		leader += 2
	elif leader != 0 and data[L - 1 - i][leader - 1] == "-":
		leader -= 2

print(int(leader / 2 + 1))