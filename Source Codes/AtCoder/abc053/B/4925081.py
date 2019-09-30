s=input()

a=[i for i, x in enumerate(s) if x == "A"]
z=[i for i, x in enumerate(s) if x == "Z"]

print(z[-1]-a[0]+1)