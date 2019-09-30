a, b = input().split()
c = int(a + b)
print("Yes" if int((c ** .5))**2 == c else "No")