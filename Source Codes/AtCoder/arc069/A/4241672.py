n,m=map(int,input().split())
print(n+(m//2-n)//2 if m//2>n else m//2)