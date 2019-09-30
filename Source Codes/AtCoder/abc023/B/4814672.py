n = int(input())
s = input()
if n%2==0:
    print("-1")
    exit()
t = n//2
l1 = s[:t]
l2 = s[t+1:][::-1]
for i in range(t):
    if l1[i]=="a":
        if l2[i]!="c":
            print(-1)
            exit()
    elif l1[i]=="b":
        if l2[i]!="b":
            print(-1)
            exit()
    elif l1[i]=="c":
        if l2[i]!="a":
            print(-1)
            exit()
    else:
        print(-1)
        exit()
else:
    print((n-1)//2)