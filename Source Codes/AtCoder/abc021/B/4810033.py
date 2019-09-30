n = int(input())
a,b = (int(i) for i in input().split())
k = int(input())
p = [int(i) for i in input().split()]

if a in p or b in p:
    print("NO")
    exit()
    
if len(list(set(p))) == len(p):
    print("YES")
else:
    print("NO")