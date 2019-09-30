N = int(input())

w = list(map(str, input().split()))
boin = ["a", "i", "o", "e", "u"]
ans = []
for i in range(N):
    bf = ""
    w[i] = w[i].lower()
    wi = list(w[i])
    for k in range(len(wi)):
        if wi[k] in boin:
            continue
        else:
            if wi[k] == "b" or wi[k] == "c":
                bf += "1"
            elif wi[k] == "d" or wi[k] == "w":
                bf += "2"
            elif wi[k] == "t" or wi[k] == "j":
                bf += "3"
            elif wi[k] == "f" or wi[k] == "q":
                bf += "4"
            elif wi[k] == "l" or wi[k] == "v":
                bf += "5"
            elif wi[k] == "s" or wi[k] == "x":
                bf += "6"
            elif wi[k] == "p" or wi[k] == "m":
                bf += "7"
            elif wi[k] == "h" or wi[k] == "k":
                bf += "8"
            elif wi[k] == "n" or wi[k] == "g":
                bf += "9"
            elif wi[k] == "z" or wi[k] == "r":
                bf += "0"
    if bf != "":
        ans.append(bf)
for i in range(len(ans)):
    if i != len(ans)-1:
        print(ans[i], end=" ")
    else:
        print(ans[i], end="")
print("")