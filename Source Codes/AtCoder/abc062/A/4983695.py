S1={1,3,5,7,8,10,12}
S2={4,6,9,11}
x,y=map(int,input().split())
print("Yes" if {x,y}<=S1 or {x,y}<=S2 else "No")