from collections import defaultdict

def p_wormhole(s):
	a, b = s.split(",")
	wormholes[int(a)].add(int(b))
	wormholes[int(b)].add(int(a))

def testCase():
	P, W = [int(v) for v in raw_input().split()]
	global wormholes
	wormholes = defaultdict(set)
	map(p_wormhole, raw_input().split())

	pos = [(0, set([0]), wormholes[0])]
	result = []
	while pos and not result or pos and result and len(pos[-1][1]) < len(result[0][1]):
		p, conquered, threatened = pos.pop(-1)
		for p2 in wormholes.get(p):
			if p2 == 1:
				result.append((1, conquered, threatened))
			elif p2 in conquered:
				continue
			else:
				c = conquered | set([p2])
				t = (threatened | wormholes[p2]) - c
				pos.append((p2, c, t))
		pos.sort(key=lambda p:(-len(p[1]),len(p[2])))

	result.sort(key=lambda p:len(p[2]))
	best = result[-1]
	return "%s %s" % (len(best[1]) - 1, len(best[2]))

if __name__ == '__main__':
	for i in xrange(int(raw_input())):
		print "Case #%d: %s" % (i + 1, testCase())
