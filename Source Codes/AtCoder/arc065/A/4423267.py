S = input()

a = len(S)

while a != 0:
    if a - 5 < 0:
        print("NO")
        exit()
    elif S[a - 1] == "m" and S[a - 5:a] == "dream":
        a -= 5
    elif S[a - 1] == "e" and S[a - 5:a] == "erase":
        a -= 5
    elif S[a - 3:a] == "mer" and a - 7 >= 0 and S[a - 7:a] == "dreamer":
        a -= 7
    elif S[a - 3:a] == "ser" and a - 6 >= 0 and S[a - 6:a] == "eraser":
        a -= 6
    else:
        print("NO")
        exit()
print("YES")