a = str(input())

if a == "a":
    print("-1")
elif len(a)>1:
    print(a[:len(a)-1])
else:print("a")