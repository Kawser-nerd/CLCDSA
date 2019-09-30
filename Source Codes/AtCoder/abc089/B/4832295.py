n=int(input())
s=input().split()
ans=len(set(s))
if ans==3:
    print("Three")
else:
    print("Four")