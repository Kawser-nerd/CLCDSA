rule = {}
for index, item in enumerate(input().split()):
	rule[str(item)] = str(index)

N = int(input())
inputs = [str(input()) for _ in range(N)]

ans = []
for item in inputs:
	cast = ''
	for string in item:
		cast += rule[string]
	ans.append((item, int(cast)))

for item in sorted(ans, key=lambda x:x[1]):
	print(item[0])