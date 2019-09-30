ar = list(input())
b = 0
while True:
    count = 0
    for i in range(1,len(ar)-1):
        if ar[i-1] != ar[i+1]:
            count +=1
            del ar[i]
            b += 1
            break
    if count == 0:
        if b % 2 == 1:
            print("First")
        else:
            print("Second")
        break