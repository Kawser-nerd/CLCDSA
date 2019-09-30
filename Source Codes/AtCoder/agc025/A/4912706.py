def sum(n):
    sum=0
    while n!=0:
        sum+=n%10
        n=n//10
    return sum



n=int(input())

min=100000

for i in range(n):
    if i==0:
        continue
    sub=n-i
    sub=sum(sub)
    i=sum(i)
    #sub?i????????
    if min>sub+i:
        min=sub+i
print(min)