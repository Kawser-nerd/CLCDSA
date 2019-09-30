S=list(input())
T=list(input())

def replacer():
	m = {}
	i = ord("A")

	def replace(c):
		nonlocal i
		if c not in m:
			m[c] = chr(i)
			i += 1
		return m[c]

	return replace

rs="".join(map(replacer(), S))
rt="".join(map(replacer(), T))

print("Yes" if rs == rt else "No")