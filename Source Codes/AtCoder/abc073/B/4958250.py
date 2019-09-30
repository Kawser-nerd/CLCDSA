n = int(input())
lr = [list(map(int, input().split())) for i in range(n)]
ninzu = 0
for i in lr:
	ninzu += i[1]-i[0]+1
print(ninzu)