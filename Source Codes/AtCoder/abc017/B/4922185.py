X = input()
X1 = X.split("ch")
X2 = "".join(X1).split("o")
X3 = "".join(X2).split("k")
X4 = "".join(X3).split("u")
if len("".join(X4))==0:
    print("YES")
else:
    print("NO")