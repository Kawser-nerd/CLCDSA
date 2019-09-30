n = input()

n = n[:-1]

while n[:len(n)//2] != n[len(n)//2:]:
  n = n[:-1]

print(len(n))