N,M,A,B = map(int, input().split())
meishi = N
for i in range(M):
    c = int(input())
    if meishi<=A: meishi += B
    meishi -= c
    if meishi<0: 
        print(i+1);  break
else:
    print("complete")