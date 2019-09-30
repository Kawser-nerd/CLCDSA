X = input()
s = input()

result = "".join([c for c in s if c not in X])

print(result)