y, m, d = map(int, input().split("/"))

if y < 2019:
    print("Heisei")
elif y == 2019 and m <= 4:
    print("Heisei")
else:
    print("TBD")