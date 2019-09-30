n = int(input())
a = int(input())
nmod = n % 500
if nmod <= a:
    print("Yes")
else:
    print("No")