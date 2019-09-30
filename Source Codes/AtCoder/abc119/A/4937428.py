s = str(input())
y = int(s[0:4])
m = int(s[5:7])
d = int(s[8:])
if y < 2019:
    print("Heisei")
elif y > 2019:
    print("TBD")
else:
    if m <= 4:
        print("Heisei")
    else:
        print("TBD")