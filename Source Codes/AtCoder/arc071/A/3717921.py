def atoi(a):

    if a=="a":
        return 0
    elif a=="b":
        return 1
    elif a=="c":
        return 2
    elif a=="d":
        return 3
    elif a=="e":
        return 4
    elif a=="f":
        return 5
    elif a=="g":
        return 6
    elif a=="h":
        return 7
    elif a=="i":
        return 8
    elif a=="j":
        return 9
    elif a=="k":
        return 10
    elif a=="l":
        return 11
    elif a=="m":
        return 12
    elif a=="n":
        return 13
    elif a=="o":
        return 14
    elif a=="p":
        return 15
    elif a=="q":
        return 16
    elif a=="r":
        return 17
    elif a=="s":
        return 18
    elif a=="t":
        return 19
    elif a=="u":
        return 20
    elif a=="v":
        return 21
    elif a=="w":
        return 22
    elif a=="x":
        return 23
    elif a=="y":
        return 24
    elif a=="z":
        return 25

def itoa(i):
    if i==0:
        return "a"
    elif i==1:
        return "b"
    elif i==2:
        return "c"
    elif i==3:
        return "d"
    elif i==4:
        return "e"
    elif i==5:
        return "f"
    elif i==6:
        return "g"
    elif i==7:
        return "h"
    elif i==8:
        return "i"
    elif i==9:
        return "j"
    elif i==10:
        return "k"
    elif i==11:
        return "l"
    elif i==12:
        return "m"
    elif i==13:
        return "n"
    elif i==14:
        return "o"
    elif i==15:
        return "p"
    elif i==16:
        return "q"
    elif i==17:
        return "r"
    elif i==18:
        return "s"
    elif i==19:
        return "t"
    elif i==20:
        return "u"
    elif i==21:
        return "v"
    elif i==22:
        return "w"
    elif i==23:
        return "x"
    elif i==24:
        return "y"
    elif i==25:
        return "z"


s = []
n = int(input())
for i in range(n):
    s.append(input())

d = [[0 for j in range(n)] for i in range(26)]

for i in range(n):
    for j in range(len(s[i])):
        d[atoi(s[i][j])][i]+=1
ans = ""
for i in range(26):
    ans+=itoa(i)*min(d[i])
print(ans)