N = int(input())
a = [int(i) for i in input().split()]

counter=0
i=0
while i<N-1:
    if(i<N-2):
        if(a[i]==a[i+1]==a[i+2]):
            counter+=1
            i+=1
        elif(a[i]==a[i+1]):
            counter+=1
        i+=1
    else:
        if(a[i]==a[i+1]):
            counter+=1
        i+=1

print(counter)