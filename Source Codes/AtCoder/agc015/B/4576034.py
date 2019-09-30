s = 0
a = input()
for i in range(len(a)):
    if a[i] == "U":
        s+=len(a)-i + 2*i-1
    else:
        s+=2*(len(a)-i-1) +i
print(s)