import collections
s = input()
t = input()

dic1 = {}
dic2 = {}
f = True
for i,j in zip(s,t):
    if i in dic1:
        if dic1[i] != j:
            f = False
    else:
        dic1[i] = j
    if j in dic2:
        if dic2[j] != i:
            f = False
    else:
        dic2[j] = i
if f:
    print("Yes")
else:
    print("No")