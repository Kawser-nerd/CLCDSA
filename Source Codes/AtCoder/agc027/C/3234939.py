import sys

n, m = map(int, input().split())
s = input()
to_a = [set() for _ in range(n)]
to_b = [set() for _ in range(n)]
for _ in range(m):
	a, b = map(int, input().split())
	if s[a-1] == "A":
		if s[b-1] == "A":
			to_a[a-1].add(b-1)
			to_a[b-1].add(a-1)
		else:
			to_b[a-1].add(b-1)
			to_a[b-1].add(a-1)
	if s[a-1] == "B":
		if s[b-1] == "B":
			to_b[a-1].add(b-1)
			to_b[b-1].add(a-1)
		else:
			to_a[a-1].add(b-1)
			to_b[b-1].add(a-1)

not_valid = set([i for i in range(n) if len(to_a[i]) * len(to_b[i]) == 0])
cnt = 0
#print(not_valid)

while not_valid:
	node = not_valid.pop()
	#print(node)
	cnt += 1

	for next_node in to_a[node]:
		if next_node == node:
			continue
		if s[node] == "A":
			to_a[next_node].remove(node)
		else:
			to_b[next_node].remove(node)

		if len(to_a[next_node]) * len(to_b[next_node]) == 0:
			not_valid.add(next_node)

	for next_node in to_b[node]:
		if next_node == node:
			continue
		if s[node] == "A":
			to_a[next_node].remove(node)
		else:
			to_b[next_node].remove(node)

		if len(to_a[next_node]) * len(to_b[next_node]) == 0:
			not_valid.add(next_node)

	#print(not_valid)

if cnt == n:
	print("No")
else:
	print("Yes")