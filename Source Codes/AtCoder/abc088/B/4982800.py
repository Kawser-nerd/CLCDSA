N=int(input())
A=sorted(list(map(int,input().split())),reverse=True)
alice=0
bob=0
for i in range(len(A)):
    if i%2==0:
        alice=alice+A[i]
    else:
        bob=bob+A[i]
print(alice-bob)