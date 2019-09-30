def main():
	n = int(input())
	said = set()
	first = input()
	said.add(first)
	last = first[-1]
	is_shiritori = True
	for _ in range(n-1):
		word = input()
		if word in said or word[0] != last:
			is_shiritori = False
		said.add(word)
		last = word[-1]

	if is_shiritori:
		print("Yes")
	else:
		print("No")


if __name__ == '__main__':
    main()