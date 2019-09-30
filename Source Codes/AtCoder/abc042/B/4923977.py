a, b = map(int, input().split())
letters = []
for i in range(a):
    c = input()
    letters.append(c)
letterss = sorted(letters)
mojiretsu = ''
for x in letterss:
    mojiretsu += x
print (mojiretsu)