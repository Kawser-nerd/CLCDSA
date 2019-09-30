N,A,B=map(int,input().split(" "))
total=0
for i in range(N+1):
    sum=0
    temp=i
    for m in range(5):
        sum+=temp%10
        temp=temp//10
    if A <= sum and sum <= B:
        total+=i

print(total)