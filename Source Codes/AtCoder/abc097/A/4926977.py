a,b,c,d = map(int,input().split())
print("Yes" if min(abs(a-c),max(abs(a-b),abs(b-c)))<=d else "No")