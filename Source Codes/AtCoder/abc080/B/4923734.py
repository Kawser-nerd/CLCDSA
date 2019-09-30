X=input()
print("Yes" if int(X)%sum(map(int,X))==0 else "No")