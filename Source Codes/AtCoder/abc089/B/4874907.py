n=int(input())
s=input()
Y=False
for w in s:
    if w=="Y":
        Y=True
if Y==True:
    print("Four")
else:
    print("Three")