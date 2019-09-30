s = sorted([i for i in input()])
t = sorted([i for i in input()],reverse =True)
if "".join(s)<"".join(t):
    print("Yes")
else:
    print("No")