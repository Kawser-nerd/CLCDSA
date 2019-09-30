a,b,c,d=map(int,input().split())
print("Yes" if (abs(a-b)<=d and abs(b-c)<=d) or abs(a-c)<=d else "No")