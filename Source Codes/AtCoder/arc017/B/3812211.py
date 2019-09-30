N,K = (int(i) for i in input().split())

#shows how numbers are continuously increasing.
conti =  1

previous = int(input())

#look up one by one.
count = 0
for i in range(1,N):
    current = int(input())
    if current > previous:
        conti += 1
    else:
        conti = 1
    #if continues for more than K numbers, that looks increasing!
    if conti >= K:
        count += 1
    #print("*" + str(conti) + "*")
    
    #to the next loop.
    previous = current
    
if K == 1:
    print(N)
else:
    print(count)