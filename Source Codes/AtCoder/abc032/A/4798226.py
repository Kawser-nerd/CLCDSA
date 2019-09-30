a = int(input())
b = int(input())
m =min(a,b)
n = int(input())
while True:
    if(n%a==0) and (n%b==0):
        print(n)
        break
    else:
        n+=1