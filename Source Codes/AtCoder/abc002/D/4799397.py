from sys import stdin
input = stdin.readline
N, M = [int(x) for x in input().rstrip().split()]
xy = [tuple([int(x) for x in input().rstrip().split()]) for _ in range(M)]
xy = set(xy)
def is_connected(node0, node1): # ????????????????
	edge = (node0, node1) if node0 < node1 else (node1, node0)
	return edge in xy

def find_kyokudai(target):
	ok = []
	not_searched = [x for x in range(1, N+1) if x != target]
	flag = 0
	ok.append(target)
	while not flag:
		for x in not_searched:
			for y in ok:
				if is_connected(y, x):
					pass
				else:
					break
			else: # ?????, ?????
				ok.append(x)
				not_searched.remove(x)
				break
		else: # ????
			flag = 1
	return len(ok)

ans = []
for i in range(1, N+1):
	ans.append(find_kyokudai(i))
print(max(ans))