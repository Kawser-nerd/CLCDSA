s=int(input())
count=2
num=s
collatz_list=[s]
while True:
    if num%2==0:
        num=num//2
    else:
        num=3*num+1
    if num in collatz_list:
        print(count)
        exit()
    else:
        collatz_list.append(num)
        count+=1