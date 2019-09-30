x,y,z=map(int,input().split())
print("?" if x-y==z and x+y==z else "+" if x+y==z else "-" if x-y==z else "!")