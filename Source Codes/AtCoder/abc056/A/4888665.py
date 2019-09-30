a, b = input().split()
a = 1 if a == "H" else -1
b = 1 if b == "H" else -1
c = a*b
if c == 1:
    ans = "H"
else:
    ans = "D"
print(ans)