N = int(input())

sum = 0
tmp = N
while tmp > 0:
    sum += tmp % 10
    tmp = tmp // 10
 
if N%sum==0:
    print("Yes")
else:
    print("No")