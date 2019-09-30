n=int(input())
r=input()
gpa={"A":4,"B":3,"C":2,"D":1,"F":0}
ans=0
for i in r:
    ans+=gpa[i]
print(ans/n)