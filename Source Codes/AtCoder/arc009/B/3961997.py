rule = {}
for index, item in enumerate(input().split()):
	rule[str(item)] = str(index)

N = int(input())
inputs = [str(input()) for _ in range(N)]

ans = []
for item in inputs:
	ans.append((item, int(''.join(rule[key] for key in item))))

for item in sorted(ans, key=lambda x:x[1]):
	print(item[0])