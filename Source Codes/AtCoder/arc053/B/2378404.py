s = input()
lis = []
num = []
cou = 0
even = 0
for n in range(len(s)):
    if s[n] in lis:continue
    else:
        num.append(s.count(s[n]))
        lis.append(s[n])

for item in num:
    cou += item % 2
    even += item

even -= cou

if cou == 0:
    print(int(len(s)))
else:
    print(int(even / (2 * cou)) * 2 + 1)