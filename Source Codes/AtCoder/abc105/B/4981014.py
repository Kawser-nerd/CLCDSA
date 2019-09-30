n=int(input())
L=[4*i+7*j for i in range(26) for j in range(15)]
print("No" if L.count(n)==0 else "Yes")