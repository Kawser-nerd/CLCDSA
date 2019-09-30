N = int(input())
s_list = []
s_set = []

for i in range(N):
	s_list.append(list(x for x in input()))

for i in s_list:
	s_set.append(set(i))

result_char = {x for x in 'qwertyuiopasdfghjklzxcvbnm'}

for i in range(N-1):
	result_char = (s_set[i] & s_set[i+1] & result_char)

result_char = list(result_char)
result_char.sort()

result = ''
for i in result_char:
	count = min(x.count(i) for x in s_list)
	result += i*count
print(result)