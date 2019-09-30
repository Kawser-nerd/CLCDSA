s=input()
a=sorted([int(i) for i in input().split()])
print(s[0:a[0]]+'"'+s[a[0]:a[1]]+'"'+s[a[1]:a[2]]+'"'+s[a[2]:a[3]]+'"'+s[a[3]:])