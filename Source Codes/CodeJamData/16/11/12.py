# Greatest character goes first
# Then the second highest (before the greatest) goes second

def solve(s):
	pre = ""
	post = ""
	part = s
	while len(part) > 0:
		c = max(list(part))
		i = len(part) - 1 - part[::-1].find(c)
		pre += c
		post = part[i+1:] + post
		part = part[:i]
	return pre+post

N = int(raw_input())
for T in range(N):
	out = "Case #" + str(T+1) + ": "
	s = raw_input()
	out += solve(s)
	print out