from collections import defaultdict
import heapq

def main():
	n, k = map(int, input().split())
	td = [0]*n
	group = defaultdict(list)
	for i in range(n):
		td[i] = list(map(int, input().split()))
		group[td[i][0]].append(td[i][1])

	grouplist = list(group.values())
	for g in grouplist:
		g.sort(reverse=True)
	grouplist.sort(key=lambda x: -x[0])

	non_maxes = []
	result = 0
	base = 0

	# i stands for total num of netas - 1
	for i in range(min(len(grouplist), k)):
		bonus = (i+1)*(i+1)
		# only use grouplist[0] to grouplist[i]
		for j, basic in enumerate(grouplist[i]):
			# new group we should add at least one neta
			if j == 0:
				if len(non_maxes) > k - (i+1):
					remove = heapq.heappop(non_maxes)
				else:
					remove = 0
				# always add each max value
				base += basic - remove
			elif len(non_maxes) < k - (i+1):
				heapq.heappush(non_maxes, basic)
				base += basic
			# new groups non-max value is larger than prior groups non-max value
			elif non_maxes and non_maxes[0] < basic:
				base += basic - non_maxes[0]
				heapq.heapreplace(non_maxes, basic)
		result = max(result, base+bonus)
	print(result)


if __name__ == '__main__':
    main()