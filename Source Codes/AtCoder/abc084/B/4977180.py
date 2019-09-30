a,b=map(int,input().split())
s=input()
list=[str(i) for i in range(10)]
print("Yes" if all([s[i] in list for i in range(a)]) and s[a]=="-" and all([s[i] in list for i in range(a+1,a+b+1)]) else "No")