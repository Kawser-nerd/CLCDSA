List=list(map(int,input().split()))
print("Yes" if sorted(List)[0]+sorted(List)[1]==sorted(List)[2] else "No")