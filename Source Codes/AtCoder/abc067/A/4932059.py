A,B=map(int,input().split())
print(["Possible","Impossible"][bool(A*B*(A+B)%3)])