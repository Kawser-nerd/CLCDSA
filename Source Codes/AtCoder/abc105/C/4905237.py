n=int(input())
s_rev=""
while n!=0:
    #s_rev+=str(-(n%(-2)))
    #n=-(n//(-2))
    s_rev+=str(n%2)
    n=n//(-2)+n%2
    #print(n)
s=""
for i in range(len(s_rev)):
    s+=s_rev[len(s_rev)-i-1]
if s=="":
    print("0")
else:
    print(s)