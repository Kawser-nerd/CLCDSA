N = int(input())
a = list(map(int,input().split()))
count_sum = 0
for i in a:
	while i % 2 == 0:
		i = i // 2
		count_sum += 1
		
		
print(count_sum)