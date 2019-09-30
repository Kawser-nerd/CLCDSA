a,b=input(),input()
n=len(a)
for i in range(n):
    a=a[1:]+a[:1]
    if a==b:
        print("Yes")
        exit()
print("No")