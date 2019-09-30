K =int(input())
A = list(map(int,input().split()))
right = sum(A)
length = len(A)
maxi = 3
mini = 2
temp1 = 2
temp2 = 2
test = A[0]

for a in A[K-2::-1]:
        if(temp1 == a and temp2 == a):
            maxi = maxi
        elif(maxi%a == a-1):
            maxi += a
        else:
            maxi += (a-1-maxi%a)
        
        if(mini%a != 0):
            mini += (a - mini%a)
        temp2 = temp1
        temp1 = a
test1 = mini
test2 = maxi
for a in A:
        test1 = test1 - test1%a
        test2 = test2 - test2%a

if(test1 == 2 and test2 == 2):
        print(mini,maxi)
else:
        print(-1)