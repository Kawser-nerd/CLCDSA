a = int(input())
br = input().split(" ")
ar = []
for b in br:
    a = ""
    for c in list(b):
        if c == "z" or c == "r" or c == "Z" or c == "R":
            a = a + "0"
        elif c == "b" or c == "c" or c == "B" or c == "C":
            a = a + "1"
        elif c == "t" or c == "j" or c == "T" or c == "J":
            a = a + "3"
        elif c == "l" or c == "v" or c == "L" or c == "V":
            a = a + "5"
        elif c == "d" or c == "w" or c == "D" or c == "W":
            a = a + "2"
        elif c == "f" or c == "q" or c == "F" or c == "Q":
            a = a + "4"
        elif c == "s" or c == "x" or c == "S" or c == "X":
            a = a + "6"  
        elif c == "p" or c == "m" or c == "P" or c == "M":
            a = a + "7"
        elif c == "h" or c == "k" or c == "H" or c == "K":
            a = a + "8"
        elif c == "n" or c == "g" or c == "N" or c == "G":
            a = a + "9"
    if a != "":
        ar.append(a)
if len(ar) == 0:
    print("")
elif len(ar) == 1:
    print(ar[0])
else:
    for i in range(len(ar)-1):
        print(ar[i] + " ",end="")
    print(ar[len(ar)-1])