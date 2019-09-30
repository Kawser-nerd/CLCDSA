#088 B
N =int(input())

A=list(map(int,input().split()))
A.sort(reverse=True)
Alice=0
Bob =0
for j,i in enumerate(A):
    if j %2==0:
        Alice+=i
    else:
        Bob+=i
print(Alice-Bob)