A,B,C = map(int,input().split())
As = [A*i for i in range(1,100)]
if all([a%B!=C for a in As]):
    print("NO")
else:
    print("YES")