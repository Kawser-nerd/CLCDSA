n=input()
print("Yes" if int(n)%sum(map(int,n))==0 else "No")