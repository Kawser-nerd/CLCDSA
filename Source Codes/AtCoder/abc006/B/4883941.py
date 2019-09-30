n = int(input())
list1 = [0,0,1]

if n == 1 or n==2:
    print(0)
elif n == 3:
    print(1)
else:
    for i in range(n-3):
        newn = (list1[i]+list1[i+1]+list1[i+2])%10007
        list1.append(newn)
    
    print(list1[-1])