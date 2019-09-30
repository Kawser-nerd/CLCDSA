n=input()
if len(n)%2==0:
    if n[0]!=n[-1]:
        print("Second")
    else:
        print("First")
else:
    if n[0]==n[-1]:
        print("Second")
    else:
        print("First")