A,B=input().split()
a=max(int("9"+A[1]+A[2]),int(A[0]+"9"+A[2]),int(A[0]+A[1]+"9"))
b=min(int("1"+B[1]+B[2]),int(B[0]+"0"+B[2]),int(B[0]+B[1]+"0"))
print(max(a-int(B),int(A)-b))