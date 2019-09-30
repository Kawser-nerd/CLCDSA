n = int(input())
temp = 0
for i in range(1,n+1):
    temp += i
#print(temp)
 
flag = 0
if n == 1:
    print("BOWWOW")
else:
    for i in range(2,temp+1):
        if temp % i == 0 and i != temp:
            print("BOWWOW")
            flag = 1
            break
    if flag == 0:
        print("WANWAN")