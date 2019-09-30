a=input()
b=input()

if len(a)>len(b):
    print("GREATER")
    exit()
elif len(a)<len(b):
    print("LESS")
    exit()
else:
    for i in range(len(a)):
        if a[i]>b[i]:
            print("GREATER")
            exit()
        elif a[i]<b[i]:
            print("LESS")
            exit()
print("EQUAL")