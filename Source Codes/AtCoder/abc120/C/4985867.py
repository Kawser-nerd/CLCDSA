s = input()

c0 = s.count("0")
c1 = s.count("1")

print(len(s) - abs(c0 - c1))